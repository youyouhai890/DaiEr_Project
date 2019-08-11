Shader "Custom/Guang" {

	SubShader{

		pass {

		Tags{ "LightMode" = "ForwardBase"}

		CGPROGRAM
#pragma vertex vert			//类似宏定义
#pragma fragment frag
#include "unitycg.cginc"	//引入顶点控制函数库
#include "Lighting.cginc"	//引入光照模型函数库

			//定义结构体,要在应用之前定义
			struct JieGouTi
		{
			float4 pos : POSITION;
			float4 color : COLOR;
		};

		//参数是引擎库自带的结构体
		JieGouTi vert(appdata_base inp)
		{
			JieGouTi jgt;

			//mvp矩阵和向量相乘,变换过后的顶点已经包含了投影算法的x,y分量的值,w分量值已经涵盖了d/1的值
			jgt.pos = UnityObjectToClipPos(inp.vertex);

			//法向量规范化
			float3 N = normalize(inp.normal);
			//世界空间里的方向光(指太阳光之类的光向量)规范化
			float3 L = normalize(_WorldSpaceLightPos0);


			//如果非等比例缩放时想要正确的结果需要相乘逆矩阵的转置矩阵,当前空间为世界空间
			//unity_ObjectToWorld和unity_WorldToObject互为逆矩阵,转置矩阵需要把相乘的矩阵放到后面(如果把行向量放在后面,隐含的意思为变成列向量(维度相同))
			N = mul(float4(N, 0), unity_WorldToObject).xyz;
			N = normalize(N);
			//获取点积结果(光强度),saturate为值的范围控制在0到1,两个相乘的向量应该处在同一个坐标系
			float dot1 = saturate(dot(N, L));
			//计算平行光
			jgt.color = _LightColor0 * dot1;

			//顶点转换为世界空间
			float3 wpos = mul(unity_ObjectToWorld, inp.vertex).xyz;
			//计算点光源+
			jgt.color.rgb += Shade4PointLights(
				unity_4LightPosX0, unity_4LightPosY0, unity_4LightPosZ0,		//内置变量作为光照参数
				unity_LightColor[0].rgb, unity_LightColor[1].rgb, unity_LightColor[2].rgb, unity_LightColor[3].rgb,	//内置变量作为光照颜色参数
				unity_4LightAtten0,	//内置变量作为衰减系数
				wpos, N		//顶点和法向量
				);
											

			return jgt;
		}

		//接受片段程序返回的COLOR语义的值
		fixed4 frag(JieGouTi jj) :COLOR
		{
			//方向光+环境光
			return jj.color + UNITY_LIGHTMODEL_AMBIENT;
		}
			ENDCG
	}
	}
		FallBack "Diffuse"
}
