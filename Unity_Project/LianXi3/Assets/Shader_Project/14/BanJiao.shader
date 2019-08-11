Shader "Custom/BanJiao" {

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

			//世界空间里的方向光(指太阳光之类的光向量)规范化
			float3 L = normalize(_WorldSpaceLightPos0);
			//法向量转换为世界空间,注意在cginc函数里包含了规范化了
			float3 N = UnityObjectToWorldNormal(inp.normal);
			//计算从定点指向摄像机的向量,调用cginc里的函数
			float3 V =normalize( WorldSpaceViewDir(inp.vertex));
			//环境光
			jgt.color = UNITY_LIGHTMODEL_AMBIENT;


			float dot1 = saturate(dot(N, L));//控制范围1到0
			//漫反射光
			jgt.color += _LightColor0 * dot1;

			//获取半角向量,获取后的半角向量也需要规范化
		    float3	H =L+V;
			H = normalize(H);

			//pow为衰减度函数,第一个参数为值, 第二个参数为倍数	,	saturate函数为范围控制到1到0
			float  JingMianFanShe = pow(saturate(dot(H, N)), _shininess);

			jgt.color.rgb += _specularColor * JingMianFanShe;

			return jgt;
		}

		//接受片段程序返回的COLOR语义的值
		fixed4 frag(JieGouTi jj) :COLOR
		{
			//方向光+环境光
			return jj.color;
		}
			ENDCG
	}
	}
		FallBack "Diffuse"
}
