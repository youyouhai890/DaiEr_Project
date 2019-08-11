
Shader "Custom/JiaoNang" {

		SubShader{
		Tags{ "Queue" = "Transparent" }
	pass {

		blend srcalpha oneminussrcalpha		//应该是半透明
			zwrite off	//关闭深度写入,缓存区里的深度保留下来
		ztest greater	//有遮挡物时取当前深度,没有遮挡物时取背景颜色

	CGPROGRAM
	#pragma vertex vert			//类似宏定义
	#pragma fragment frag
	#include "unitycg.cginc"	//导入引擎库

#pragma target 3.0	//可以用偏导函数

			struct JieGouTi
			{
				float4 pos : POSITION;
				float2 uv : TEXCOORD0;
			};

		//参数是引擎库自带的结构体
		JieGouTi vert(appdata_full inp)
		{
			JieGouTi jgt;
			//把模型空间转换为世界空间
			jgt.pos = UnityObjectToClipPos(inp.vertex);
			return jgt;
		}
		//接受片段程序返回的COLOR语义的值
		fixed4 frag(JieGouTi jgt) :COLOR
		{
			fixed4 col = fixed4(1,1,1,1);	//白色
			return col;
		}
			ENDCG
	}
	/////////////////////////////////////////////
		pass {

			blend srcalpha oneminussrcalpha		//应该是半透明
		//ztest lequal	//有遮挡物时取遮挡物的颜色,没有遮挡物时取当前颜色
				CGPROGRAM
#pragma vertex vert			//类似宏定义
#pragma fragment frag
#include "unitycg.cginc"	//导入引擎库

#pragma target 3.0	//可以用偏导函数

				struct JieGouTi
			{
				float4 pos : POSITION;
				float2 uv : TEXCOORD0;
			};

			//参数是引擎库自带的结构体
			JieGouTi vert(appdata_full inp)
			{
				JieGouTi jgt;
				//把模型空间转换为世界空间
				jgt.pos = UnityObjectToClipPos(inp.vertex);
				return jgt;
			}
			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jgt) :COLOR
			{
				fixed4 col = fixed4(1,1,0,1);	//黄色
			return col;
			}
				ENDCG
		}


	}
		FallBack "Diffuse"
}
