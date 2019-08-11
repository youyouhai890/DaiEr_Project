Shader "Custom/NewSurfaceShader" {
	Properties {
		_MainTex ("纹理", 2D) = "" {}
	_uv("uv",range(-0.009,0.009))=0
	}
		SubShader{
				pass {
				CGPROGRAM
	#pragma vertex vert			//类似宏定义
	#pragma fragment frag
	#include "unitycg.cginc"	//导入引擎库

			sampler2D _MainTex;
			float _uv;

			//定义结构体,要在应用之前定义
			struct JieGouTi
			{
				float4 pos : POSITION;
				float2 uv : TEXCOORD0;
			};

			//参数是引擎库自带的结构体
			JieGouTi vert(appdata_base inp)
			{
				JieGouTi jgt;
				//把模型空间转换为世界空间
				jgt.pos = UnityObjectToClipPos(inp.vertex);
				//获取纹理坐标
				jgt.uv = inp.texcoord.xy;
				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jj) :COLOR
			{

				//从纹理坐标采样(可理解为贴图)
				//float4 col = tex2D(_MainTex,jj.uv);
				float4 col = tex2D(_MainTex,float2(_uv,0.1));
				return col;
			}

				ENDCG
		}
	}
	FallBack "Diffuse"
}
