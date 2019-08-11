Shader "Custom/QieXianKongJian" {
	Properties{

	WenLi("纹理1", 2D) = "" {}

	}
	SubShader{

		pass {

		Tags{ "LightMode" = "ForwardBase"}

		CGPROGRAM
#pragma vertex vert			//类似宏定义
#pragma fragment frag
#include "unitycg.cginc"	//引入顶点控制函数库
#include "Lighting.cginc"	//引入光照模型函数库

			sampler2D WenLi;


			//定义结构体,要在应用之前定义
			struct JieGouTi
		{
			float2 uv:TEXCOORD0;
			float3 wpos:TEXCOORD1;
			float3 GuangXIngLiang:TEXCOORD2;
			float4 pos : POSITION;
			float4 color : COLOR;

		};

		//参数是引擎库自带的结构体
		JieGouTi vert(appdata_full v)
		{
			JieGouTi jgt;

			//mvp矩阵和向量相乘,变换过后的顶点已经包含了投影算法的x,y分量的值,w分量值已经涵盖了d/1的值
			jgt.pos = UnityObjectToClipPos(v.vertex);
			jgt.wpos = mul(unity_ObjectToWorld,v.vertex).xyz;
			jgt.uv = v.texcoord.xy;	//存储纹理的uv坐标

			//三角形的顶点总是有一个法线,这个法线已经作为了纹理空间当中的基向量(基轴,如x轴(1,0,0))
			//顶点的切线与顶点的法线的叉积获取垂直于这两个基轴的基向量
			//float3 B = cross(v.tangent.xyz,v.normal);
			//坐标系总是有三个基轴(基向量(x轴(1,0,0) , y轴(0,1,0),z轴(0,0,1))
//用下面的三个坐标当作基轴((顶点切线(t), 切线和法线的叉积(B), 顶点法线(n),)构造一个新的坐标空间,这种空间纹理空间或切线空间
			//float3x3 rotation = float3x3(v.tangent.xyz, B ,v.normal);
			
			//内置宏,可以替代上面两行代码
			TANGENT_SPACE_ROTATION;


			//_WorldSpaceLightPos0为内置变量,如果是平行光记录的是方向,如果是点光源记录的是位置信息
			//_WorldSpaceLightPos0如果是点光源它的w分量不会为0,如果是平行光它的w分量会为0
			//把平行光(光向量_WorldSpaceLightPos0)旋转到纹理空间
			jgt.GuangXIngLiang = mul(rotation, _WorldSpaceLightPos0.xyz);
				

			return jgt;
		}

		//接受片段程序返回的COLOR语义的值
		fixed4 frag(JieGouTi jgt) :COLOR
		{

			//世界空间里的方向光(指太阳光之类的光向量)规范化
			float3 L = normalize(jgt.GuangXIngLiang);
			//采样后的颜色值转换成法向量的值
			float3 N = UnpackNormal(tex2D(WenLi,jgt.uv));
			N = normalize(N);//规范化


			//获取法向量与光向量的夹角强度
			float dot1 = saturate(dot(N, L));
			//计算平行光颜色
			float4 col = _LightColor0 * dot1;

			//计算点光源+
			col.rgb += Shade4PointLights(
				unity_4LightPosX0, unity_4LightPosY0, unity_4LightPosZ0,		//内置变量作为光照参数
				unity_LightColor[0].rgb, unity_LightColor[1].rgb, unity_LightColor[2].rgb, unity_LightColor[3].rgb,	//内置变量作为光照颜色参数
				unity_4LightAtten0,	//内置变量作为衰减系数
				jgt.wpos, N		//顶点和法向量
			);

			//方向光+环境光
			return col + UNITY_LIGHTMODEL_AMBIENT;
		}
			ENDCG
	  }
	//////////////////////////////////////////////////////////////////
	pass {

		Tags{ "LightMode" = "ForwardAdd" }   //ForwardAdd能够对像素的点光源进行渲染
		blend one one

				
			CGPROGRAM
#pragma vertex vert			//类似宏定义
#pragma fragment frag
#include "unitycg.cginc"	//引入顶点控制函数库
#include "Lighting.cginc"	//引入光照模型函数库

			sampler2D WenLi;


		//定义结构体,要在应用之前定义
		struct JieGouTi
		{
			float2 uv:TEXCOORD0;
			float3 wpos:TEXCOORD1;
			float3 GuangXIngLiang:TEXCOORD2;
			float4 pos : POSITION;
			float4 color : COLOR;

		};

		//参数是引擎库自带的结构体
		JieGouTi vert(appdata_full v)
		{
			JieGouTi jgt;

			//mvp矩阵和向量相乘,变换过后的顶点已经包含了投影算法的x,y分量的值,w分量值已经涵盖了d/1的值
			jgt.pos = UnityObjectToClipPos(v.vertex);
			jgt.wpos = mul(unity_ObjectToWorld,v.vertex).xyz;
			jgt.uv = v.texcoord.xy;	//存储纹理的uv坐标

									//三角形的顶点总是有一个法线,这个法线已经作为了纹理空间当中的基向量(基轴,如x轴(1,0,0))
									//顶点的切线与顶点的法线的叉积获取垂直于这两个基轴的基向量
									//float3 B = cross(v.tangent.xyz,v.normal);
									//坐标系总是有三个基轴(基向量(x轴(1,0,0) , y轴(0,1,0),z轴(0,0,1))
									//用下面的三个坐标当作基轴((顶点切线(t), 切线和法线的叉积(B), 顶点法线(n),)构造一个新的坐标空间,这种空间纹理空间或切线空间
									//float3x3 rotation = float3x3(v.tangent.xyz, B ,v.normal);

									//内置宏,可以替代上面两行代码
			TANGENT_SPACE_ROTATION;


			//_WorldSpaceLightPos0为内置变量,如果是平行光记录的是方向,如果是点光源记录的是位置信息
			//_WorldSpaceLightPos0如果是点光源它的w分量不会为0,如果是平行光它的w分量会为0
			//把平行光(光向量_WorldSpaceLightPos0)旋转到纹理空间
			jgt.GuangXIngLiang = mul(rotation, _WorldSpaceLightPos0.xyz);


			return jgt;
		}

		//接受片段程序返回的COLOR语义的值
		fixed4 frag(JieGouTi jgt) :COLOR
		{

			//世界空间里的方向光(指太阳光之类的光向量)规范化
			float3 L = normalize(jgt.GuangXIngLiang);
			//采样后的颜色值转换成法向量的值
			float3 N = UnpackNormal(tex2D(WenLi,jgt.uv));
			N = normalize(N);//规范化

			//获取法向量与光向量的夹角强度
			float dot1 = saturate(dot(N, L));

			float ShuaiJian = 1;
			//_WorldSpaceLightPos0如果是点光源它的w分量不会为0,如果是平行光它的w分量会为0
			if (_WorldSpaceLightPos0.w !=0)
			{
				//计算衰减
				ShuaiJian = 1 / length(jgt.GuangXIngLiang);
			}

			//计算平行光颜色
			float4 col = _LightColor0 * dot1 *ShuaiJian;

			//计算点光源+
			col.rgb += Shade4PointLights(
				unity_4LightPosX0, unity_4LightPosY0, unity_4LightPosZ0,		//内置变量作为光照参数
				unity_LightColor[0].rgb, unity_LightColor[1].rgb, unity_LightColor[2].rgb, unity_LightColor[3].rgb,	//内置变量作为光照颜色参数
				unity_4LightAtten0,	//内置变量作为衰减系数
				jgt.wpos, N		//顶点和法向量
			);

			//方向光+环境光
			return col + UNITY_LIGHTMODEL_AMBIENT;
		}
			ENDCG
	}


	}
		FallBack "Diffuse"
}
