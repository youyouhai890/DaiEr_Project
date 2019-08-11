Shader "Custom/PianDuan" {


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
			float3 normal:TEXCOORD1;	//法向量
			float4 vertex:COLOR;	//光向量
		};

		//参数是引擎库自带的结构体
		JieGouTi vert(appdata_base inp)
		{
			JieGouTi jgt;

			//mvp矩阵和向量相乘,变换过后的顶点已经包含了投影算法的x,y分量的值,w分量值已经涵盖了d/1的值
			jgt.pos = UnityObjectToClipPos(inp.vertex);
			//法向量和光向量需要放到片段程序里处理
			jgt.normal = inp.normal;
			jgt.vertex =inp.vertex;
		
			return jgt;
		}

		//接受片段程序返回的COLOR语义的值
		fixed4 frag(JieGouTi jgt) :COLOR
		{
			//统一规范化和转换到世界空间的法向量和顶点到光源,调用cginc里的函数
		    float3 N = UnityObjectToWorldNormal(jgt.normal);
			float3 L = normalize(WorldSpaceLightDir(jgt.vertex));

			//环境光,调用文档里的内容(内置变量里可查找)
			fixed4 col = UNITY_LIGHTMODEL_AMBIENT;
	    	float diffuseScale = saturate(dot(N, L));
			//漫反射
			col += _LightColor0 * diffuseScale;

		
			return  col;
		}
			ENDCG
	}
	}
		FallBack "Diffuse"
}
