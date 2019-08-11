using System.Collections;
using System.Collections.Generic;
using System.Threading;
using UnityEngine;

public class CUV : MonoBehaviour {

    public int width;   //128
    public int height;

    //定义二维数组,交换能量值(波纹)的两个缓存区
    float[,] waveA;
    float[,] waveB;
    Color[] ColorBuffer;    //颜色缓存

    //传递给着色器(shader)的纹理值
    Texture2D C_WenLi;

    bool isRun = true;
    int sleepTime;

	// Use this for initialization
	void Start () {
        
        //初始化
        waveA = new float[width , height];
        waveB = new float[width , height];
        C_WenLi = new Texture2D( width , height );  //应该是理解成位图,数组的每个元素理解成一个像素

        ColorBuffer = new Color[width * height];    //初始化颜色缓存

        GetComponent<Renderer>().material.SetTexture( "C_WenLi" , C_WenLi );    //传递给shader的纹理图

        QiShiDian(0,0);    //赋初始值,相当于往中心点投入石头

        //启用子线程
        Thread th = new Thread(new ThreadStart(JiSuanNengLiang));
        th.Start();
	}
	
	// Update is called once per frame
	void Update () {

        sleepTime = (int)(Time.deltaTime * 1000);  //要暂停子线程的秒数
        C_WenLi.SetPixels(ColorBuffer);   //不能在非主线程下使用,说明update里面是主线程
        C_WenLi.Apply();            //不能在非主线程下使用,说明update里面是主线程
                                    // Debug.Log("111111");
                                    // Debug.Log( "Time.deltaTime---------" + Time.deltaTime );
                                    // if ( Input.GetMouseButtonDown(0) )// 0为鼠标左键

        ShuiBoZuoBiao();

        //JiSuanNengLiang();
    }

    void ShuiBoZuoBiao()
    {
        if (Input.GetMouseButtonDown(0))// 鼠标点击
        {
            Debug.Log("22222");
            RaycastHit CunChuSheXianJieGuo; //用来存储射线的结果

            //从鼠标点击坐标发出射线(屏幕点发出射线)碰撞物体后的结果
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

            if (Physics.Raycast(ray, out CunChuSheXianJieGuo))
            {
                Vector3 pos = (CunChuSheXianJieGuo.point);    //获取坐标(世界坐标)
                pos = transform.worldToLocalMatrix.MultiplyPoint(pos);    //世界坐标转换成本地坐标(-0.5到0.5)
                Debug.Log(pos);

                //求水波纹起始点的坐标(w,h)
                //(pos.x +0.5 )为把值-0.5到0.5控制到0到1, 关键思路在于设定了0到1的边界,然后乘以固定量就可获得对应位置 
                int w = (int)((pos.x + 0.5) * width);
                int h = (int)((pos.y + 0.5) * height);

                QiShiDian(w, h); //波纹的起始点,类似投入石头
            }
        }

    }


    //生成波的起始点,类似往水里投石头,参数为位图(数组[128])的元素位置
    void QiShiDian(int x,int y)
    {

        int BanJing = 15;   //半径
        float JuLi;     //距离

        for ( int i = -BanJing  ; i <= BanJing ; i++ )
        {
            for ( int j = -BanJing ; j <= BanJing ; j++ )
            {
                if (         ((x+i>=0)&&(x+i<width-1))      //不超过起始点x的半径
                          && ((y+j>=0)&&(y+j<height-1))      //不超过起始点y的半径
                    )
                {
                    JuLi = Mathf.Sqrt( i * i + j * j );     //求距离,sqrt为平方根,结果肯定得正数
                    if ( JuLi<BanJing )
                    {
                        //利用周期函数Cos给起始点赋值 , 除法运算可理解为一种比例运算
                        waveA[x + i , y + j] = Mathf.Cos( JuLi * Mathf.PI / BanJing );
                    }
                }
            }
        }
        ////起始点设定为中心点
        //waveA[width / 2 , height / 2] = 1;
        ////一下中心点的8个方位
        //waveA[width / 2-1 , height / 2] = 1;
        //waveA[width / 2-1 , height / 2+1] = 1;
        //waveA[width / 2 , height / 2+1] = 1;
        //waveA[width / 2 +1, height / 2+1] = 1;
        //waveA[width / 2+1 , height / 2] = 1;
        //waveA[width / 2+1 , height / 2-1] = 1;
        //waveA[width / 2 , height / 2-1] = 1;
        //waveA[width / 2-1 , height / 2-1] = 1;

    }


    void JiSuanNengLiang()
    {
        while ( isRun )
        {

            //为了防止越界所以从1开始或width-1,因为w-1或w+1的时候可能越界
            for ( int w = 1 ; w < width-1 ; w++ )
            {
                for ( int h = 1 ; h < height-1 ; h++ )
                {
                    //能量计算,缓存区(内存)进行反复的切换二维数组
                    // waveB和 waveA必须一样,这样才能得到正确的效果
                    waveB[w , h] = (
                                 waveA[w - 1 , h] +
                                 waveA[w - 1 , h + 1] +
                                 waveA[w , h + 1] +
                                 waveA[w + 1 , h + 1] +
                                 waveA[w + 1 , h] +
                                 waveA[w + 1 , h - 1] +
                                 waveA[w , h - 1] +
                                 waveA[w - 1 , h - 1]
                        ) / 4 - waveB[w , h];

                    //设定值范围,最大不能超过1,最小不能超过-1
                    float value = waveB[w , h];
                    if ( value>1 )
                    {
                        waveB[w , h] = 1;
                    }
                    if ( value<-1 )
                    {
                        waveB[w , h] = -1;
                    }

                    //计算偏移,然后把这个值放到颜色值里传递给shader
                    float offset_u = ( waveB[w - 1 , h] - waveB[w + 1 , h] ) / 2;
                    float offset_v = ( waveB[w , h - 1] - waveB[w , h + 1] ) / 2;


                    float r = offset_u/2 + 0.5f;   //把-1到1的范围控制到1到0,把这个值传递到shader里当作u值
                    float g = offset_v/2 + 0.5f;   //把-1到1的范围控制到1到0,把这个值传递到shader里当作v值

                    //C_WenLi.SetPixel( w , h , new Color( r , g , 0 ) ); //不能在非主线程下使用
                    ColorBuffer[w + width * h] = new Color( r , g , 0 ); //可以在非主线程下使用

                    waveB[w , h] -= waveB[w , h] * 0.1f;   //把衰减度设置到接近0,值为-1到1

                }
            }

           // C_WenLi.Apply(); //启用像素设定,不能在非主线程下使用

            //交换数组,形成水波
            float[,] temp = waveA;
            waveA = waveB;
            waveB = temp;

            Thread.Sleep(sleepTime);    //暂停N秒

        }

    }


    void OnDestory()    //脚本关闭时启用该函数
    {
        isRun = false;
    }

}
