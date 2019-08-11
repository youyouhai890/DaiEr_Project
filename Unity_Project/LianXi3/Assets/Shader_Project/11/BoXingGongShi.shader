Shader "Custom/BoXingGongShi" {

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

				//波形公式:  振幅(运动的上下幅度) * sin(频率 * 周期(间隔) + 初相(比如时间为0时向位在哪里))
				//	A * sin(w*x + t)

					//振幅和频率是1所以先忽略
					inp.vertex.y += 0.3 * sin((inp.vertex.x * inp.vertex.z)  + _Time.y);
					//inp.vertex.y += 0.2 * sin( (inp.vertex.x+ inp.vertex.z)   + _Time.w);

					//float4x4 SuoFang = {
					//	float4(sin(HuDu)/8+0.5,0,0,0),
					//	float4(0,1,0,0),
					//	float4(0,0,1,0),
					//	float4(0,0,0,1)
					//};

					//inp.vertex = mul(SuoFang, inp.vertex);

					//mvp矩阵和向量相乘,变换过后的顶点已经包含了投影算法的x,y分量的值,w分量值已经涵盖了d/1的值
					jgt.pos = UnityObjectToClipPos(inp.vertex);
					jgt.color = fixed4(0, inp.vertex.y, 0,1);
					
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
