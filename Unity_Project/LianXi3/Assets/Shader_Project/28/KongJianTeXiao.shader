
Shader "Custom/KongJianTeXiao" {
	Properties {
		_MainTex("纹理", 2D) = "white" {}
	_MainTex2("纹理", 2D) = "" {}
	_F("大小",range(1,10)) = 4
		_A("衰减",range(0.01,0.1))=0.05
		_Speed("活动速度",range(0.1,5))=2
		//_T("透明度",range(0.1,5)) = 0.2
		_L("亮度",range(1,5)) =1

	}
		SubShader{
		Tags{ "Queue" = "Transparent" }			//表示当前对象透明(渲染队列)

	pass {
			//最终输出的颜色为红绿蓝
			colormask rgb

				CGPROGRAM
	#pragma vertex vert			//类似宏定义
	#pragma fragment frag
	#include "unitycg.cginc"	//导入引擎库
	
#pragma target 3.0	//可以用偏导函数

					sampler2D _MainTex;
				sampler2D _MainTex2;
				float _uv;
				float _F;
				float _A;
				float _L;
				//float _T;
				float _Speed;

			
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

				float2 uv = jgt.uv;
				fixed4 col = tex2D(_MainTex, uv);	//采样
				float offset = _A * sin(uv*_F + _Time.y *_Speed);

				//2维向量跟一维向量相加 , 等于给2维的每个分量相加
				//uv += offset;
				//uv.y += 0.3;	//整体偏移向下移动0.3
				fixed4 col1 = tex2D(_MainTex2, uv);	//采样

				float2 uv2 = jgt.uv;	//重置
				float JuLi = distance(uv2, float2(0.4, 0.5));	//distance为计算距离的函数
				float offset2 = 0.2 * sin(JuLi*2*_F + _Time.x *_Speed);
				uv2 += offset2;
				fixed4 col2 = tex2D(_MainTex2, uv2*5);	//采样

				col *= col1.b + col2	;
				return col;
			}

				ENDCG
		}
	/////////////////////////////////////////////
	}
	FallBack "Diffuse"
}
