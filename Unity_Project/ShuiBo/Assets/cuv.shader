
Shader "Custom/cuv" {
	Properties {
		_MainTex("纹理", 2D) =""
	}
		SubShader{

	pass {
			//最终输出的颜色为红绿蓝
			colormask rgb

				CGPROGRAM
	#pragma vertex vert			//类似宏定义
	#pragma fragment frag
	#include "unitycg.cginc"	//导入引擎库
	
#pragma target 3.0	//可以用偏导函数

			sampler2D _MainTex;
			sampler2D C_WenLi;	//C#里穿过来的纹理
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
				jgt.uv = inp.texcoord;
				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jgt) :COLOR
			{
				float2 uv = tex2D(C_WenLi,jgt.uv).xy;
				uv = uv * 2 - 1;	//把1到0的值控制到-1到1
				uv *= 0.5;	   //偏转率(应该是偏移比例换算),乘法运算为改变整体,值越大波纹越明显
				jgt.uv += uv;	//应该是偏移

				fixed4 col = tex2D(_MainTex, jgt.uv);	//采样
				return col;
			}

				ENDCG
		}
	/////////////////////////////////////////////
	}
	FallBack "Diffuse"
}
