Shader "Custom/NewSurfaceShader" {
	Properties
	{
		BanJingFanWei("半径范围",range(0,5)) = 1	//半径初始值为1
		YiDongZhongXin("移动中心",range(-5,5))=1 	//半径初始值为1
	}
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
	
			float BanJingFanWei;	//重新定义属性
			float YiDongZhongXin;	//重新定义属性

			//参数是引擎库自带的结构体
			JieGouTi vert(appdata_base inp)
			{
					JieGouTi jgt;

					//把模型空间转换为世界空间
					float4 ShiJie = mul(unity_ObjectToWorld,inp.vertex);
					
					//由于是平面所以取xz的值
					float2 xz = ShiJie.xz;
					
					//获取两点之间的距离公式,这里的0表示中心点
					//float JuLi = sqrt((xz.x - 0) * (xz.x - 0) + (xz.y - 0)*(xz.y - 0));

					
					//length计算两点之间的距离长度(一维),xz为世界坐标-float2(YiDongZhongXin,0)作为世界中心点
					//float JuLi = BanJingFanWei - length(xz-float2(YiDongZhongXin,0));	
					float JuLi =length(float2(1, inp.vertex.z));

					//检测是否超过半径(1)范围,如果值为小于0表示超过了范围(不抬高山峰)
					float JianCeFanWei = JuLi < 0 ? 0 : JuLi;
					float GaoDu = 1;
					//存储顶点数据,然后重新赋值给模型
					float4 MoXingDingDian = float4(inp.vertex.x, GaoDu * JianCeFanWei, inp.vertex.z, inp.vertex.w);

					//mvp矩阵和向量相乘,变换过后的顶点已经包含了投影算法的x,y分量的值,w分量值已经涵盖了d/1的值
					float4 m = UnityObjectToClipPos(MoXingDingDian);
					jgt.color = fixed4(MoXingDingDian.y, MoXingDingDian.y, MoXingDingDian.y,1);
					jgt.pos = m;	//获取变换过后的向量
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
