Shader "Custom/TouSHi" {
SubShader{

	pass {
		CGPROGRAM
		#pragma vertex vert			//类似宏定义
		#pragma fragment frag

		#include "unitycg.cginc"	//导入引擎库
		
			//定义结构体,要在应用之前定义
			struct JieGouTi
			{
				float4 pos : POSITION;
				float4 color : COLOR;
			};

		float	dis;
		float	r;

			//参数是引擎库自带的结构体
			JieGouTi vert(appdata_base inp)
			{
					JieGouTi jgt;
					//mvp矩阵和向量相乘,变换过后的顶点已经包含了投影算法的x,y分量的值,w分量值已经涵盖了d/1的值
					float4 m = UnityObjectToClipPos(inp.vertex);	
					jgt.pos = m;	//获取变换过后的向量

					//投影算法,把3d物体投影到2d屏幕
					//x为屏幕横向坐标值范围为-1到1
					float x = jgt.pos.x / jgt.pos.w;
					
					if(x>dis && x<dis+r)	//介于屏幕dis到dis+r之间
					{
						jgt.color = fixed4(1, 0, 0, 1);
					}
					else {
						//设置颜色灰度系数,屏幕x的值范围-1到1,而颜色的值范围是0到1,所以需要转换一下
						jgt.color = fixed4(x / 2 + 0.5, x / 2 + 0.5, x / 2 + 0.5, 1);
					}

				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jj) :COLOR
			{
				//把位置输出为颜色值
				//	return  fixed4(0,1,1,1);
				return jj.color;
			}

			ENDCG
    	}
	}
	FallBack "Diffuse"
}
