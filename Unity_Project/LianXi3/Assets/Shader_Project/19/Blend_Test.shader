// Upgrade NOTE: replaced 'mul(UNITY_MATRIX_MVP,*)' with 'UnityObjectToClipPos(*)'

Shader "Custom/Blend_Test" {
	Properties {

		_MainColor("主颜色",color)=(1,1,1,1)
		_ShuaiJian ("衰减度(次方)", Range(1,8)) = 2
		_outer("顶点延伸控制系数",Range(0,1))=0.2
	}
	SubShader {
		Tags{ "Queue" = "Transparent" }			//表示当前对象透明(渲染队列)

		pass {

// 第一个参数srcalpha 表示 当前颜色值 * srcalpha(当前alpha值)
// 第二个参数OneMinusSrcAlpha 表示 上一个计算后的颜色值(已经在屏幕里的) * OneMinusSrcAlpha( 1 - 当前颜色的alpha) 结果:alpha值越小,相乘后颜色越深
// 最后计算结果相加(相加后的效果为不同颜色叠加),由于点积效果反转后90度时结果为1所以越接近边缘越不透明(alpha的值为1时不透明)
		blend srcalpha OneMinusSrcAlpha	//中间alpha为1(不透明)所以是白色(1,1,1),边缘alpha(0)最透明
		//	blend srcalpha srcalpha
			zwrite off   //(关闭深度写入) ;半透明物体写入深度时背面会被剔除,失去透明效果变得漆黑一片,所以要关闭深度写入

			CGPROGRAM
				//Tags{ "RenderType" = "Opaque" }
	#pragma vertex vert			//类似宏定义
	#pragma fragment frag
	#include "unitycg.cginc"	//引入顶点控制函数库
	#include "Lighting.cginc"	//引入光照模型函数库

		float4 _MainColor;
		float _ShuaiJian;
		float _outer;
				struct JieGouTi
			{
				float4 pos : POSITION;
				float3 normal : TEXCOORD0;
				float4 vertex : TEXCOORD1;
			};

			JieGouTi  vert(appdata_base v)
			{
				//顶点按照法向量的方向延伸,用倍数来控制
				v.vertex.xyz += v.normal * _outer;
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
				
				float LiangDu = saturate(dot(N, V));	//把反转(1-)取消后,点积结果为中心点的值最大(1)
				LiangDu = pow(LiangDu, _ShuaiJian);//设置衰减度(pow为次方计算)


				 //只修改alpha的值,值越高越不透明(1)
				_MainColor.a *= LiangDu;
				return _MainColor;	//接近边缘时alpha值最大

			}
		ENDCG
		}
	/////////////////////////////////////////////////////第二个pass通道
	pass {
		//blend zero one	//相当于给当前pass注释
			//上一个pass为//中间alpha为1(不透明)所以是白色(1,1,1),边缘alpha(0)最透明
			BlendOp RevSub	//从目标减源(当前pass),由于当前颜色为1(最大),相减后颜色为肯定黑色(0,0,0,1),注意当前pass没计算顶点延伸值
			//blend srcalpha OneMinusSrcAlpha	//计算后的源(当前pass)颜色(1,1,1,1) + 上一个颜色(0,0,0)
			blend DstAlpha one	//上一次渲染后源(黑色)(0,0,0,1) * 目标alpha(中心点最大(1))=(0,0,0,1)(黑色中心点),推算边缘为白色透明(1,1,1,0)
			zwrite off   //(关闭深度写入) ;半透明物体写入深度时背面会被剔除,失去透明效果变得漆黑一片,所以要关闭深度写入

			CGPROGRAM
			//Tags{ "RenderType" = "Opaque" }
			#pragma vertex vert			//类似宏定义
			#pragma fragment frag
			#include "unitycg.cginc"	//引入顶点控制函数库
			#include "Lighting.cginc"	//引入光照模型函数库

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
						return o;
					}

					fixed4 frag(JieGouTi IN) :COLOR{

						return fixed4(1,1,1,1);	

					}
			ENDCG
		}
	////////////////////////////////////////////////////////////////////////第三个pass
	pass {
		//上一个计算后的颜色值(不是return值)为黑色(0,0,0,1)
		//blend zero one	//相当于给当前pass注释
			blend srcalpha OneMinusSrcAlpha	//结果为中心点白色
			zwrite off   //(关闭深度写入) ;半透明物体写入深度时背面会被剔除,失去透明效果变得漆黑一片,所以要关闭深度写入

			CGPROGRAM
			//Tags{ "RenderType" = "Opaque" }
#pragma vertex vert			//类似宏定义
#pragma fragment frag
#include "unitycg.cginc"	//引入顶点控制函数库
#include "Lighting.cginc"	//引入光照模型函数库

			float4 _MainColor;
		float _ShuaiJian;
		float _outer;
		struct JieGouTi
		{
			float4 pos : POSITION;
			float3 normal : TEXCOORD0;
			float4 vertex : TEXCOORD1;
		};

		JieGouTi  vert(appdata_base v)
		{
			//顶点按照法向量的方向延伸,用倍数来控制
			v.vertex.xyz += v.normal * _outer;
			JieGouTi o;
			o.pos = UnityObjectToClipPos(v.vertex);	//mvp矩阵转换
			o.vertex = v.vertex;
			o.normal = v.normal;

			return o;
		}

		fixed4 frag(JieGouTi IN) :COLOR{
			//float3 N = normalize(mul((IN.normal, (float3x3)unity_WorldToObject));	//应该是非等比例
			float3 N = UnityObjectToWorldNormal(IN.normal);	//调用库函数,转换成世界法线已经包含规范化

			float3 V = WorldSpaceViewDir(IN.vertex);	//调用库函数,顶点指向摄像机(世界空间)
			V = normalize(V);
			//点积计算时90度时结果为0,效果反转后90度时结果为1,所以接近边缘时最亮
			float LiangDu = saturate(dot(N, V));	//(1.0 - )表示反转结果,saturate表示把点积的结果控制在1到0
			LiangDu = pow(LiangDu, _ShuaiJian);//设置衰减度(pow为次方计算)

			//只修改alpha的值,值越高越不透明(1)
			_MainColor.a *= LiangDu;
			return _MainColor;	//接近边缘时alpha值最大



		}
			ENDCG
	}

	}
	FallBack "Diffuse"
}
