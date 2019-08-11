
Shader "Custom/Qiang2" {

		SubShader{
		Tags{ "Queue" = "Transparent" "rendertype" = "Transparent" }	//设置被置换的shader
	pass {

		blend srcalpha oneminussrcalpha		//应该是半透明
		//	zwrite off	//关闭深度写入,只进行颜色输出,那么当比较深度时,比较的是上一个(空值???)写入的深度
		//ztest greater	//当前胶囊的深度值(Z)写入到深度缓存区,所以下一次渲染时(墙面渲染)应该是基于当前胶囊的深度值(大于)来跟墙进行比较

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
			fixed4 col = fixed4(1,0,0,0.5);	//红色
			return col;
		}
			ENDCG
	}
//////////////////////////////////////////
	}
		FallBack "Diffuse"
}
