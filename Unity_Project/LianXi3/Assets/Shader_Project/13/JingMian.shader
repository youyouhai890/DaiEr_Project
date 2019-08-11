Shader "Custom/JingMian" {

	properties{
		_specularColor("镜面反射",color) = (1,1,1,1)
		_shininess("衰减度",range(1,64))=8	//初始为8倍
	}

	SubShader{

		pass {

		Tags{ "LightMode" = "ForwardBase"}

		CGPROGRAM
#pragma vertex vert			//类似宏定义
#pragma fragment frag
#include "unitycg.cginc"	//引入顶点控制函数库
#include "Lighting.cginc"	//引入光照模型函数库

			float4 _specularColor;	//定义
			float _shininess;	//定义

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

			//转换坐标系
			float3 wpos = mul(unity_ObjectToWorld, inp.vertex).xyz;
			//从光源指向顶点(统一坐标系为世界空间)
			//float3 I = wpos - _WorldSpaceLightPos0;
			//结果为同上,调用Cginc里的函数(计算从光源指向顶点),由于Cginc里求的是从顶点指向光源的向量所以要取反(-)
			float3 I = -WorldSpaceLightDir(inp.vertex);
			//求反射光函数,参数为 第一个参数为从光源指向顶点的向量,第二个参数为法向量
		    float3	R = reflect(I,N);
			//计算从定点指向摄像机的向量,调用cginc里的函数
			float3 V = WorldSpaceViewDir(inp.vertex);
			//规范化
			R = normalize(R);
			V = normalize(V);
			//pow为衰减度函数,第一个参数为值, 第二个参数为倍数	,	saturate函数为范围控制到1到0
			float  JingMianFanShe = pow(saturate(dot(R,V)), _shininess);

			jgt.color.rgb += _specularColor * JingMianFanShe;

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
