// Upgrade NOTE: replaced 'mul(UNITY_MATRIX_MVP,*)' with 'UnityObjectToClipPos(*)'

// Upgrade NOTE: replaced 'mul(UNITY_MATRIX_MVP,*)' with 'UnityObjectToClipPos(*)'


Shader "Custom/mvp" {

		SubShader{
			pass {

			CGPROGRAM
			#pragma vertex vert			//类似宏定义
			#pragma fragment frag

			#include "unitycg.cginc"	//导入引擎库


			float4x4 mvp;	//定义外部矩阵
			float4x4 SuoFang;	//定义外部矩阵
			
			//定义结构体,要在应用之前定义
			struct JieGouTi
			{
				float4 pos : POSITION;
			};

			//参数是引擎库自带的结构体
			JieGouTi vert(appdata_base inp)
			{
				JieGouTi jgt;		
				float4 m = mul(mvp,inp.vertex);	//mvp矩阵和向量相乘
				jgt.pos = m;	//跟旋转矩阵相乘
				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jj) : COLOR
			{
				//把位置输出为颜色值
			//	return  fixed4(0,1,1,1);
				return jj.pos;
			}

			ENDCG
		}
	}
	FallBack "Diffuse"
}
