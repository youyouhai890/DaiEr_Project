Shader "Custom/NewSurfaceShader" {
	//Properties {
	//	_Color ("Color", Color) = (1,1,1,1)
	//	_MainTex ("Albedo (RGB)", 2D) = "white" {}
	//	_Glossiness ("Smoothness", Range(0,1)) = 0.5
	//}
	SubShader{
		pass
		{

			CGPROGRAM		//CG语句开头,类似main函数

			#pragma vertex vert			//类似宏定义
			#pragma fragment frag

		



			//参数in ojPos为对象坐标  , out pos为输出的顶点坐标 out为col输出的颜色
			//顶点程序
			void vert(in float2 ojPos:POSITION,out float4 pos : POSITION,out float4 col : COLOR) 
			{
				pos = float4(ojPos,0,1);
				col = pos;
			 }


			//参数inout col为从顶点程序获取到的参数
			void frag(inout float4 col:COLOR)
			{
				
				col.y = float1(0.5);

			}


			ENDCG

		}


	}
		FallBack "Diffuse"
}