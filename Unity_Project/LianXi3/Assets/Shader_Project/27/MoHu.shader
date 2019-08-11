﻿
Shader "Custom/MoHu" {
	Properties {
		_MainTex("纹理", 2D) = "white" {}


	//_uv("uv",range(-0.009,0.009))=0
	}
		SubShader{
				pass {
				CGPROGRAM
	#pragma vertex vert			//类似宏定义
	#pragma fragment frag
	#include "unitycg.cginc"	//导入引擎库
	
#pragma target 3.0	//可以用偏导函数

			sampler2D _MainTex;
			float _uv;
			float4 _MainTex_ST;	//_MainTex_ST为Unity里的内置变量,可自动获取平移和偏移的数据

			
			struct JieGouTi
			{
				float4 pos : POSITION;
				float2 uv : TEXCOORD0;
				float z : TEXCOORD1;
			};

			//参数是引擎库自带的结构体
			JieGouTi vert(appdata_full inp)
			{
				JieGouTi jgt;
				//把模型空间转换为世界空间
				jgt.pos = UnityObjectToClipPos(inp.vertex);
				jgt.uv = TRANSFORM_TEX(inp.texcoord, _MainTex);
				jgt.z = mul(unity_ObjectToWorld,inp.vertex).z;		
				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jgt) :COLOR
			{

				float2 uv = jgt.uv;


				//用z轴进行求导数(变化量)的值
				float2 dsdx=ddx(jgt.z)*10;
				float2 dsdy = ddy(jgt.z)*10;

				//tex2D的重载方法,可使用偏导函数 , 导数: 在某一时刻的变化率.偏导数也是导数
		//如果我们对求导数的自变量给的是一个常量(不可变的量),导数的结果总是为0,我们可以把uv看成是一个0到1之间的变化率,所以可以把uv当作导数的变化量
				//只对u坐标进行偏移采样,v坐标不做偏移, 
				fixed4 col = tex2D(_MainTex, uv, dsdx, dsdy);	//采样

				return col;
			}

				ENDCG
		}
	}
	FallBack "Diffuse"
}