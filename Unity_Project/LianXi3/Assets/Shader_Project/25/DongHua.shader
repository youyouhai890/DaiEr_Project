
Shader "Custom/DongHua" {
	Properties {
		_MainTex("纹理", 2D) = "white" {}
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
			float4 _MainTex_ST;	//_MainTex_ST为Unity里的内置变量,可自动获取平移和偏移的数据

			
			struct JieGouTi
			{
				float4 pos : POSITION;
				float2 uv : TEXCOORD0;
				float2 uv2 : TEXCOORD1;
			};

			//参数是引擎库自带的结构体
			JieGouTi vert(appdata_full inp)
			{
				JieGouTi jgt;
				//把模型空间转换为世界空间
				jgt.pos = UnityObjectToClipPos(inp.vertex);

				//_MainTex_ST为Unity里平移和偏移的内置变量,_MainTex_ST.xy为平移,_MainTex_ST.zw偏移
				 //jgt.uv = inp.texcoord.xy * _MainTex_ST.xy + _MainTex_ST.zw;
				//调用内置的宏(获取uv)
				jgt.uv = TRANSFORM_TEX(inp.texcoord, _MainTex);

				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jgt) :COLOR
			{

				//从纹理坐标采样(可理解为贴图)
				//float4 col = tex2D(_MainTex,jj.uv);
				float4 col = tex2D(_MainTex,jgt.uv);

				return col;
			}

				ENDCG
		}
	}
	FallBack "Diffuse"
}
