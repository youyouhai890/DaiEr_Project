Shader "Custom/NewSurfaceShader 1" {
	Properties {
		_MainTex ("Albedo (RGB)", 2D) = "white" {}
		_Color ("Color", Color) = (1,1,1,1)
		_Glossiness ("Smoothness", Range(0,1)) = 0.5
		_Metallic ("Metallic", Range(0,1)) = 0.0
////////////////////////////////////////
			_MainColor("上面颜色",color) = (1,1,1,1)	//白色
			_TwoColor("下面颜色",color) = (0,0,0,1)		//黑色(不透明)
			_BianJie("控制边界", Range(-0.26,0.26)) = 0
			_R("半径", Range(0.01,0.25)) = 0.2
	}
	SubShader {
		Tags { "RenderType"="Opaque" }
		LOD 200

		CGPROGRAM
		// Physically based Standard lighting model, and enable shadows on all light types
#pragma surface surf Standard vertex:vert fullforwardshadows
//#pragma surface surf Standard fullforwardshadows

		// Use shader model 3.0 target, to get nicer looking lighting
		#pragma target 3.0

		sampler2D _MainTex;

		struct Input {
			float2 uv_MainTex;
			///////////////文档添加部分
			float3 customColor;
			////////////////自己代码镶嵌
			float y;// TEXCOOD0;	//面编程封装了底层,所以后面不需要带语义
		};

		half _Glossiness;
		half _Metallic;
		fixed4 _Color;

		//////////////

		float4 _MainColor;
		float4 _TwoColor;
		float _BianJie;
		float _R;



		UNITY_INSTANCING_BUFFER_START(Props)
			// put more per-instance properties here
		UNITY_INSTANCING_BUFFER_END(Props)

		void vert(inout appdata_full v, out Input o) {
			//UNITY_INITIALIZE_OUTPUT(Input, o);	//猜测这个宏是给纹理(uv)赋值的
			o.uv_MainTex = v.texcoord.xz;	//手动赋值,替代上一行的宏定义	
			o.customColor = abs(v.normal);
			o.y = v.vertex.y;		//获取模型的y轴
		}

		void surf (Input IN, inout SurfaceOutputStandard o) {
			// Albedo comes from a texture tinted by color
			fixed4 c = tex2D (_MainTex, IN.uv_MainTex) * _Color;
			o.Albedo = c.rgb;
			// Metallic and smoothness come from slider variables
			o.Metallic = _Metallic;
			o.Smoothness = _Glossiness;
			o.Alpha = c.a;

			////////////////下面是从我的代码镶嵌后的代码//////////////////

			//求任意(所以)一个向量从顶点到边界的距离,只范围为1到-1
			float JuLi = IN.y - _BianJie;
			float ZhengJuLi = abs(JuLi);	//求绝对值正数只有0和1
			float fl3 = step(ZhengJuLi, _R);	//A<=B ,返回1否则0,长度不能超过半径

			float FuHao = JuLi / ZhengJuLi;	//值只有-1或1,检测是否有符号(负数),主要识别有负数的模型下方顶点

			float b = ZhengJuLi / _R;	//所有比例计算1到0

			float PiPei_BiLi = FuHao * b;	//每个像素匹配所有比例
			//PiPei_BiLi = fl3 * PiPei_BiLi;	//半径以内的分配颜色,其他0(半径以外)
											//  PiPei_BiLi = step(0.4, PiPei_BiLi);
			PiPei_BiLi = PiPei_BiLi / 2 + 0.5;	//把-1到1的值范围控制到0到1到0.5
												//	BiLi = saturate(BiLi);	//把范围不要超过0到1
			float qz = abs(_BianJie);	//取边界长度,绝对值用于取负数情况时的长度
			float fh = qz / (_BianJie);	//取所有顶点符号
			//float zj = step(qz, 0.25);	//检测长度是否超过边界长度,不超过的话返回1,超过返回0
			float zj = step(0.25,qz);	//qz检测长度是否超过边界长度,不超过的话返回0,超过返回1

				
				//颜色相乘后获得叠加的效果									
				//插值运算 lerp = (_MainColor.rgba * (1 - PiPei_BiLi)) + (_TwoColor.rgba * PiPei_BiLi);
			//实现颜色超过边界取反效果,最最最主要的思路为真(1)时输出另一个颜色
			o.Albedo *= lerp(  ((1-zj)*_MainColor) + (zj * _TwoColor), ((1 - zj)*_TwoColor) + (zj * _MainColor), PiPei_BiLi);


		}
		ENDCG
	}
	FallBack "Diffuse"
}
