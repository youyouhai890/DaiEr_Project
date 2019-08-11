using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class faxian : MonoBehaviour {

    public Texture2D tex0;
    public Texture2D tex1;


	// Use this for initialization
	void Start () {

        //h从1和255开始是因为不让数组超出边界
        for ( int h = 1 ; h < 256-1 ; h++ )
        {
            for ( int w = 1 ; w < 256-1 ; w++ )
            {
                //GetPixel返回color类型,由于黑色和白色之中三个分量(r,g,b)都一样,所以取哪个分量都可以
                float uleft = tex0.GetPixel( w - 1 , h ).r;
                float uright = tex0.GetPixel( w + 1 , h ).r;
                float u = uright - uleft;   //用左右两个像素的差值做深度

                float vtop = tex0.GetPixel( w , h - 1 ).r;
                float vbottom = tex0.GetPixel( w , h + 1 ).r;
                float v = vbottom - vtop;   //用上下两个像素的差值做深度

                //深度(Z)值影响垂直于平面的倾斜度
                Vector3 vector_u = new Vector3( 1 , 0 , u );//x轴向量的Z深度作为法线高度
                Vector3 vector_v = new Vector3( 0 , 1 , v );//y轴向量的Z深度作为法线高度

                //两个向量的叉积(求法线),然后规范化
                Vector3 N = Vector3.Cross( vector_u , vector_v ).normalized;
                
                //把法线的值从-1到1控制到0到1
                float r = N.x * 0.5f + 0.5f;
                float g = N.y * 0.5f + 0.5f;
                float b = N.z * 0.5f + 0.5f;

                ///把法线的值存到颜色里,当在shader里采样(用uv来获取颜色值)时可以获取法线的值
                tex1.SetPixel(w,h, new Color( r , g , b ) );
                //tex1.SetPixel(w,h, new Color(0, g , 0 , r ) );

            }
        }

            tex1.Apply( false );

	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
