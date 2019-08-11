Shader "Custom/CubiMap" {
	Properties {

		_CubeMap ("立方体纹理", cube) = "" {}

	}
		SubShader{
				pass {
				CGPROGRAM
	#pragma vertex vert			//类似宏定义
	#pragma fragment frag
	#include "unitycg.cginc"	//导入引擎库

			samplerCUBE _CubeMap;		//定义立方体纹理

			//定义结构体,要在应用之前定义
			struct JieGouTi
			{
				float4 pos : POSITION;
				float3 FanSheXiangLiang : TEXCOORD0;
			};

			//参数是引擎库自带的结构体
			JieGouTi vert(appdata_base inp)
			{
				JieGouTi jgt;
				//把模型空间转换为世界空间
				jgt.pos = UnityObjectToClipPos(inp.vertex);

				//需要实时变化的值(比如摄像机(人的眼睛)),这样立方体文理随着摄像机变化
				//摄像机到顶点(视向量,理解成人的眼睛),向量前面有负号(-)表示反方向(在reflect函数里用到这种视向量)
				float3 SheXiangJiDaoDingDian =  -WorldSpaceViewDir(inp.vertex);

				//把法向量变换到世界空间,跟视向量统一坐标空间,
				float3 N = mul(inp.normal,(float3x3)unity_WorldToObject);
				N = normalize(N);
				//获取反射向量R
				jgt.FanSheXiangLiang = reflect(SheXiangJiDaoDingDian, N);
				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi IN) :COLOR
			{

				//从纹理坐标采样(可理解为贴图)
				//float4 col = tex2D(_MainTex,jj.uv);
				float4 col = texCUBE(_CubeMap,IN.FanSheXiangLiang);
				return col;
			}
				ENDCG
		}

	}
	FallBack "Diffuse"
}
