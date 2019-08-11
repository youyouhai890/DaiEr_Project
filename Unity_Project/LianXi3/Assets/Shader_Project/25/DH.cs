using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DH : MonoBehaviour {

    public int width;   //宽比例
    public int height;  //高比例
    public int  fps = 1;

    int currentIndex;   //循环因子
	// Use this for initialization
	IEnumerator Start () {
        //获取材质相关对象
        Material mat = GetComponent<Renderer>().material;

        float SuoFang_x = 1.0f / width; //uv缩放x(平铺)//可理解为末点采样
        float SuoFang_y = 1.0f / height; //uv缩放y  //可理解为末点采样
        //Debug.Log( "缩放的值为-------"+ SuoFang_y );
        while ( true )
        {
            //同一个(currentIndex)范围内的x偏移,SuoFang_x(末尾采样)可理解为偏移单位,currentIndex % width可理解为偏移的比例(偏移数量)
            float PianYi_x = currentIndex % width * SuoFang_x;  
            float PianYi_y = currentIndex / height * SuoFang_y; //同一个(currentIndex)范围内的y轴偏移
           Debug.Log( "currentIndex--"+currentIndex+" / height-----"+height+"----"+currentIndex / height ); //  1/3 = 0  , 2/3 = 0
          // Debug.Log( "currentIndex--"+currentIndex+" % width-----"+width+"----"+currentIndex % width); 

            mat.SetTextureOffset( "_MainTex" , new Vector2( PianYi_x , PianYi_y ) );  //调整shader纹理的偏移位置
            mat.SetTextureScale( "_MainTex" , new Vector2( SuoFang_x , SuoFang_y ) );  //调整shader纹理的缩放(平铺)

             yield return new WaitForSeconds( 1.0f / fps );
           Debug.Log( "当前帧每秒-----"+fps );

            //计算循环范围
            currentIndex = (++currentIndex) % (width * height) ;
        //   Debug.Log( "currentIndex-----"+currentIndex );

        }
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
