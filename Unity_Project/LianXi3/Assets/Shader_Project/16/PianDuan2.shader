Shader "Custom/PianDuan2" {
	properties{
		_MainColor("主颜色",color) = (1,1,1,1)
		_specularColor("镜面反射",color) = (1,1,1,1)
		_shininess("衰减度",range(1,64)) = 8	//初始为8倍
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
		float4 _MainColor;	//定义
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
			//环境光,调用文档里的内容(内置变量里可查找)
			fixed4 col = UNITY_LIGHTMODEL_AMBIENT;

			//统一规范化和转换到世界空间的法向量和顶点到光源,调用cginc里的函数
		    float3 N = UnityObjectToWorldNormal(jgt.normal);
			float3 L = normalize(WorldSpaceLightDir(jgt.vertex));

			//漫反射,用主颜色值来调整方向光颜色
	    	float diffuseScale = saturate(dot(N, L));
			col += _LightColor0 *_MainColor* diffuseScale;


			//顶点到摄像机,调用CG函数
			float3 V = normalize(WorldSpaceViewDir(jgt.vertex));

			//求反射光公式
			float3 R = 2 * dot(N,L) * N - L;
			//镜面反射点积(夹角)
			float JingMianFanShe = saturate(dot(R, V));
			//求衰减度
			 col += _specularColor * pow(JingMianFanShe, _shininess);


			 //顶点转换为世界空间
			 float3 wpos = mul(unity_ObjectToWorld, jgt.vertex).xyz;
			 //计算点光源,调用Cg函数,参数为Unity内置变量,参数可以用C#来自定义值
			 col.rgb += Shade4PointLights(
				 unity_4LightPosX0, unity_4LightPosY0, unity_4LightPosZ0,		//内置变量作为光照参数
				 unity_LightColor[0].rgb, unity_LightColor[1].rgb, unity_LightColor[2].rgb, unity_LightColor[3].rgb,	//内置变量作为光照颜色参数
				 unity_4LightAtten0,	//内置变量作为衰减系数
				 wpos, N		//顶点和法向量
			 );


			return  col;
		}
			ENDCG
	}
	}
		FallBack "Diffuse"
}
