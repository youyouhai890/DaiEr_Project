// Upgrade NOTE: replaced 'mul(UNITY_MATRIX_MVP,*)' with 'UnityObjectToClipPos(*)'

Shader "Custom/DingDian" {
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
				float4 m = UnityObjectToClipPos(inp.vertex);	//mvp矩阵和向量相乘
				jgt.pos = m;	//获取变换过后的向量

				//float4 wpos = mul(unity_ObjectToWorld, inp.vertex); //模型空间转换为世界空间

				if (inp.vertex.x == 0.5) {
				//	if (jgt.pos.x == 0.5) {
					//_SinTime和_CosTime的值范围是-1到1,而颜色的值范围是1到1,所以 /2+0.5 表示把时间因子的值控制在0到1
					jgt.color = fixed4(_SinTime.w/2+0.5, _CosTime.w/2+0.5, _SinTime.y/2+0.5, 1);
				}
				else {
					jgt.color = fixed4(1, 1, 0, 1);		//输出颜色
				}
				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jj):COLOR
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
