Shader "Custom/NiuQu" {

SubShader{

	pass {
		CGPROGRAM
		#pragma vertex vert			//类似宏定义
		#pragma fragment frag
		#include "unitycg.cginc"	//导入引擎库
		
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

					//用向量长度作为弧度
					//	float HuDu = length(inp.vertex) * _SinTime.w;
					//float HuDu = inp.vertex.z * _Time.y;	//用模型的z轴的所有向量作为变换的长度单位
					float HuDu = inp.vertex.z + _Time.y;	//用模型的z轴的所有向量作为变换的长度单位


					//旋转矩阵,绕Y轴旋转
					//float4x4 m = {
					//	float4(cos(HuDu),0,sin(HuDu),0),
					//	float4(0,1,0,0),
					//	float4(-sin(HuDu),0,cos(HuDu),0),
					//	float4(0,0,0,1)
					//};

					////用矩阵变换顶点,矩阵相乘最好在mvp之前(优化)
					////inp.vertex = mul(m, inp.vertex);

					////上面的顶点和矩阵相乘优化后的代码
					//float x = inp.vertex.x * cos(HuDu) + inp.vertex.z * sin(HuDu);
					//float z = inp.vertex.x * (-sin(HuDu)) + inp.vertex.z * cos(HuDu);
					////inp.vertex.x = x;
					////inp.vertex.z = z;
					//inp.vertex.xz = float2(x, z);
					//缩放矩阵
					float4x4 SuoFang = {
						float4(sin(HuDu)/8+0.5,0,0,0),
						float4(0,1,0,0),
						float4(0,0,1,0),
						float4(0,0,0,1)
					};
					inp.vertex = mul(SuoFang, inp.vertex);



					//mvp矩阵和向量相乘,变换过后的顶点已经包含了投影算法的x,y分量的值,w分量值已经涵盖了d/1的值
					jgt.pos = UnityObjectToClipPos(inp.vertex);
					jgt.color = fixed4(HuDu, 1, 0,1);
					
				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jj) :COLOR
			{
				//把位置输出为颜色值
				//	return  fixed4(0,1,1,1);
				return jj.color;
			}

			ENDCG
    	}
	}
	FallBack "Diffuse"
}
