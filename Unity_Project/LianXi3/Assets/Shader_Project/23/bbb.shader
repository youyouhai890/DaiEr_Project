Shader "Custom/bbb" {
	Properties {
		_MainTex ("纹理", 2D) = "" {}
	//_uv("uv",range(-0.009,0.009))=0
	}
		SubShader{
				pass {
				CGPROGRAM
	#pragma vertex vert			//类似宏定义
	#pragma fragment frag
	#include "unitycg.cginc"	//导入引擎库

			sampler2D _MainTex;
			float _uv;

			//_MainTex_ST为Unity里平移和偏移的内置变量,_MainTex_ST.xy为平移,_MainTex_ST.zw偏移
			float4 _MainTex_ST;

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

				//_MainTex_ST为Unity里平移和偏移的内置变量,_MainTex_ST.xy为平移,_MainTex_ST.zw偏移
				 //jgt.uv = inp.texcoord.xy * _MainTex_ST.xy + _MainTex_ST.zw;

				//调用内置的宏
				jgt.uv =  TRANSFORM_TEX(inp.texcoord.xy, _MainTex);


				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jj) :COLOR
			{

				//从纹理坐标采样(可理解为贴图)
				//float4 col = tex2D(_MainTex,jj.uv);
				float4 col = tex2D(_MainTex,jj.uv);
				return col;
			}

				ENDCG
		}
	}
	FallBack "Diffuse"
}
