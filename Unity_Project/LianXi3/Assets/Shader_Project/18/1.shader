// Upgrade NOTE: replaced 'mul(UNITY_MATRIX_MVP,*)' with 'UnityObjectToClipPos(*)'

Shader "Custom/1" {
	Properties {

		_ShuaiJian ("衰减度", Range(1,8)) = 2
	}
	SubShader {
		Tags{ "Queue" = "Transparent" }			//表示当前对象透明(渲染队列)

		pass {

// 第一个参数srcalpha 表示 当前颜色值 * srcalpha(当前alpha值)
// 第二个参数OneMinusSrcAlpha 表示 上一个计算后的颜色值(已经在屏幕里的) * OneMinusSrcAlpha( 1 - 当前颜色的alpha) 结果:alpha值越小,相乘后颜色越深
// 最后计算结果相加(相加后的效果为不同颜色叠加),由于点积效果反转后90度时结果为1所以越接近边缘越不透明(alpha的值为1时不透明)
		blend srcalpha OneMinusSrcAlpha
		//	blend srcalpha srcalpha
			zwrite off   //(关闭深度写入) ;半透明物体写入深度时背面会被剔除,失去透明效果变得漆黑一片,所以要关闭深度写入

			CGPROGRAM
				//Tags{ "RenderType" = "Opaque" }
	#pragma vertex vert			//类似宏定义
	#pragma fragment frag
	#include "unitycg.cginc"	//引入顶点控制函数库
	#include "Lighting.cginc"	//引入光照模型函数库

				float _ShuaiJian;
				struct JieGouTi
			{
				float4 pos : POSITION;
				float3 normal : TEXCOORD0;
				float4 vertex : TEXCOORD1;
			};

			JieGouTi  vert(appdata_base v)
			{
				JieGouTi o;
				o.pos = UnityObjectToClipPos(v.vertex);	//mvp矩阵转换
				o.vertex = v.vertex;
				o.normal = v.normal;

				return o;
			}

			fixed4 frag(JieGouTi IN) :COLOR{
				//float3 N = normalize(mul((IN.normal, (float3x3)unity_WorldToObject));	//应该是非等比例
				float3 N = UnityObjectToWorldNormal(IN.normal);	//调用库函数,转换成世界法线已经包含规范化
				 
				//float3 worldPos = mul(unity_ObjectToWorld, IN.vertex).xyz;	//调用库函数,把顶点转换成世界空间
				//float3 V =_WorldSpaceCameraPos.xyz - worldPos;	//调用库函数,顶点指向摄像机(世界空间)
				//结果同上面的两行
				float3 V= WorldSpaceViewDir(IN.vertex);	//调用库函数,顶点指向摄像机(世界空间)
				V = normalize(V);
				//点积计算时90度时结果为0,效果反转后90度时结果为1,所以接近边缘时最亮
				float LiangDu = 1.0 - saturate(dot(N, V));	//(1.0 - )表示反转结果,saturate表示把点积的结果控制在1到0
				LiangDu = pow(LiangDu, _ShuaiJian);//设置衰减度(pow为次方计算)
				return fixed4(1,1,1,1) * LiangDu;	//接近边缘时alpha值最大

			}
		ENDCG
		}
	}
	//FallBack "Diffuse"
}
