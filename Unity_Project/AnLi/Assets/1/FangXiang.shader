Shader "Custom/FangXiang" {
	Properties {
		_Color ("Color", Color) = (1,1,1,1)
		_MainTex ("Albedo (RGB)", 2D) = "white" {}
		_Glossiness ("Smoothness", Range(0,1)) = 0.5
		_Metallic ("Metallic", Range(0,1)) = 0.0
	}
	SubShader {
		Tags { "RenderType"="Opaque" }
		Tags{ "Queue" = "Transparent" }			//表示当前对象透明(渲染队列)
		LOD 200

		CGPROGRAM
		#pragma surface surf Standard vertex:vert fullforwardshadows
		#pragma target 3.0

		sampler2D _MainTex;

		struct Input {		//结构体
			float2 uv_MainTex;
			float4 pos;
		};

		half _Glossiness;
		half _Metallic;
		fixed4 _Color;


		UNITY_INSTANCING_BUFFER_START(Props)
		UNITY_INSTANCING_BUFFER_END(Props)


			//参数是引擎库自带的结构体
		Input vert(inout appdata_full IN)
		{
			Input jgt;
			//把模型空间转换为世界空间
			float4 m = UnityObjectToClipPos(IN.vertex);
			jgt.pos = m;	//获取变换过后的向量
			return jgt;
		}

		void surf (Input IN, inout SurfaceOutputStandard o) {

			IN.uv_MainTex = float2(1-IN.uv_MainTex.y, IN.uv_MainTex.x);
			fixed4 c = tex2D (_MainTex, IN.uv_MainTex) * _Color;
			c = 1-c.rgba * c.a;
			o.Albedo = c.rgb;
			o.Metallic = _Metallic;
			o.Smoothness = _Glossiness;
			o.Alpha = c.a;
		}
		ENDCG
	}
	FallBack "Diffuse"
}
