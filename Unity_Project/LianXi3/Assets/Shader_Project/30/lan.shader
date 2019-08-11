
Shader "Custom/lan" {

		SubShader{
		Tags{ "Queue" = "Transparent" }
		pass {

		blend srcalpha oneminussrcalpha		//应该是半透明
			zwrite off

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
			fixed4 col = fixed4(0,0,1,0.5);	//采样
		return col;
		}

			ENDCG
	}
	/////////////////////////////////////////////
	}
		FallBack "Diffuse"
}
