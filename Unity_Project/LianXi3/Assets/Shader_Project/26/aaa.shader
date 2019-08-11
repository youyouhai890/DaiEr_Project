
Shader "Custom/aaa" {
	Properties {
		_MainTex("纹理", 2D) = "white" {}
	_F("倍数",range(1,30)) = 10
		_A("衰减",range(0,0.1)) = 0.01
		_R("半径",range(0,1)) = 0

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
			float _F;
			float _A;	//衰减
			float _R;
			
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
				jgt.uv = TRANSFORM_TEX(inp.texcoord, _MainTex);

				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jgt) :COLOR
			{

				float2 uv = jgt.uv;
				 uv = uv* (100 *sin(_Time.x * 3.14*0.01));



				//采样就是在源图的指定坐标上取颜色
				//把输出的BiLi作为有颜色区分开来显示,  由于BiLi可能有负值所以控制范围(saturate)0到1 , 100是倍数(高亮)
				fixed4 col = tex2D(_MainTex, uv);// +fixed4(1, 1, 1, 1)*uv.x;

				return col;
			}

				ENDCG
		}
	}
	FallBack "Diffuse"
}
