Shader "Custom/NewSurfaceShader" {
	Properties{

		_MainColor("上面颜色",color) = (1,1,1,1)	//白色
		_TwoColor("下面颜色",color) = (0,0,0,1)		//黑色(不透明)
		_BianJie("控制边界", Range(-0.5,0.5)) = 0
		_R("半径", Range(0,0.5)) = 0.2
	}
	SubShader{
		//Tags{ "Queue" = "Transparent" }
		pass {

			CGPROGRAM

			#pragma vertex vert			//类似宏定义
			#pragma fragment frag
			#include "unitycg.cginc"	//引入顶点控制函数库
			#include "Lighting.cginc"	//引入光照模型函数库

			float4 _MainColor;
			float4 _TwoColor;
			float _BianJie;
			float _R;

			//定义结构体,要在应用之前定义
			struct JieGouTi
			{
				float4 pos : POSITION;
				//float4 col : COLOR;
				float y : TEXCOOD0;
				//float y : COLOR;
			};

			//参数是引擎库自带的结构体
			JieGouTi vert(appdata_base v)
			{
				JieGouTi o;
				//mvp
				o.pos = UnityObjectToClipPos(v.vertex);
				o.y = v.vertex.y;

				return o;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jgt) :COLOR
			{
				//全部匹配和,1符号(检测模型下方)

				//求任意(所以)一个向量从顶点到边界的距离,只范围为1到-1
				float JuLi = jgt.y - _BianJie;
				float ZhengJuLi = abs(JuLi);	//求绝对值正数只有0和1
				float fl3 = step(ZhengJuLi, _R);	//A<=B ,返回1否则0,长度不能超过半径

				float FuHao = JuLi / ZhengJuLi;	//值只有-1或1,检测是否有符号(负数),主要识别有负数的模型下方顶点

				float b = ZhengJuLi/_R;	//所有比例计算1到0

				float PiPei_BiLi = FuHao * b;	//每个像素匹配所有比例
				PiPei_BiLi = fl3 * PiPei_BiLi;	//半径以内的分配颜色,其他0(半径以外)
			  //  PiPei_BiLi = step(0.4, PiPei_BiLi);
				PiPei_BiLi = PiPei_BiLi / 2 + 0.5;	//把-1到1的值范围控制到0到1到0.5
				//	BiLi = saturate(BiLi);	//把范围不要超过0到1

				//插值运算 lerp = (_MainColor.rgba * (1 - PiPei_BiLi)) + (_TwoColor.rgba * PiPei_BiLi);
				 float4 col = lerp(_MainColor, _TwoColor, PiPei_BiLi);
				 return	col;

			}
			ENDCG
		}

	}
		FallBack "Diffuse"
}
