Shader "Custom/YinYing" {
	properties{
		_MainColor("主颜色",color) = (1,1,1,1)
		_specularColor("镜面反射",color) = (1,1,1,1)
		_shininess("衰减度",range(1,64)) = 8	//初始为8倍
	}

	SubShader{
		//pass {
		////阴影投射
		//Tags{ "LightMode" = "ShadowCaster" }
		//}

		pass {

		Tags{ "LightMode" = "ForwardBase"}

		CGPROGRAM
#pragma vertex vert			//类似宏定义
#pragma fragment frag
#pragma multi_compile_fwdbase	//多编译相关
#include "unitycg.cginc"	//引入顶点控制函数库
#include "Lighting.cginc"	//引入光照模型函数库
#include "AutoLight.cginc"	//引入阴影相关库

			float4 _specularColor;	//定义
		float4 _MainColor;	//定义
		float _shininess;	//定义

		//	//定义结构体,要在应用之前定义
			struct JieGouTi
		{
			float4 pos : POSITION;
			float3 normal:TEXCOORD1;	//法向量
			float4 vertex:COLOR;	//光向量

			//unityShadowCoord3 _LightCoord : TEXCOORD0;
			//unityShadowCoord3 _ShadowCoord : TEXCOORD2;
			LIGHTING_COORDS(0, 2)
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
		
			//调用宏
			TRANSFER_VERTEX_TO_FRAGMENT(jgt)



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

			//方向光+环境光
			 float atten = LIGHT_ATTENUATION(jgt);
			//return jgt.color + UNITY_LIGHTMODEL_AMBIENT;

				 col.rgb *= atten;

			return  col;
		}
			ENDCG
	}
	/////////////////////////////////////////////////////////////////////////////////
	pass {		//一个pass渲染一次,第二个pass再渲染一次

		Tags{ "LightMode" = "ForwardAdd" }	//每像素计算(最好光照在片段程序里计算)
	blend one one		//第一个one为当前pass(通道)的所有计算都通过  ,第二个one为上一个pass的所有计算都通过
			CGPROGRAM
#pragma vertex vert			//类似宏定义
#pragma fragment frag
#pragma multi_compile_fwdadd_fullshadows 	//多编译计算所有阴影
#include "unitycg.cginc"	//引入顶点控制函数库
#include "Lighting.cginc"	//引入光照模型函数库
#include "AutoLight.cginc"	//引入阴影相关库

			float4 _specularColor;	//定义
		float4 _MainColor;	//定义
		float _shininess;	//定义							
		struct JieGouTi
		{
			float4 pos : POSITION;
			float3 normal:TEXCOORD1;	//法向量
			float4 vertex:COLOR;	//光向量
			float4 col:TEXCOORD5;
									//unityShadowCoord3 _LightCoord : TEXCOORD0;
									//unityShadowCoord3 _ShadowCoord : TEXCOORD2;
			LIGHTING_COORDS(0, 2)
		};

		//参数是引擎库自带的结构体
		JieGouTi vert(appdata_base v)
		{
			JieGouTi jgt;

			//mvp矩阵和向量相乘,变换过后的顶点已经包含了投影算法的x,y分量的值,w分量值已经涵盖了d/1的值
			jgt.pos = UnityObjectToClipPos(v.vertex);
			//法向量和光向量需要放到片段程序里处理
			jgt.normal = v.normal;
			jgt.vertex = v.vertex;
			
			//调用宏
			TRANSFER_VERTEX_TO_FRAGMENT(jgt)

				return jgt;
		}

		//接受片段程序返回的COLOR语义的值
		fixed4 frag(JieGouTi jgt) :COLOR
		{
			//由于上一个pass里已经计算了环境光所以第二个pass里不用计算
		float4 col = {0,0,0,0};

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

		//给结构体赋值的宏
		//float atten = LIGHT_ATTENUATION(jgt);	//4.0++以后的函数库应用
		UNITY_LIGHT_ATTENUATION(atten,jgt, wpos);	//5.0++以后的函数库调用
		// float atten=(tex2D(_LightTexture0, dot(jgt._LightCoord, jgt._LightCoord).rr).UNITY_ATTEN_CHANNEL * SHADOW_ATTENUATION(a))
		col.rgb *= atten;

		return  col;
		}
			ENDCG
	}


	}
		FallBack "Diffuse"
}
