Shader "Custom/1" {

	SubShader{
		pass
		{

		   CGPROGRAM		//CG语句开头,类似main函数
			 #pragma vertex vert			//类似宏定义
			 #pragma fragment frag
			


			//参数in ojPos为对象坐标  , out pos为输出的顶点坐标 out为col输出的颜色
			//顶点程序
			void vert(in float4 ojPos:POSITION,out float4 pos:POSITION,out float4 col:COLOR) {


			 
			   pos = ojPos;
			   
			   
			}


		   //参数inout col为从顶点程序获取到的参数
			void frag(inout float4 col:COLOR)
			{
				//col;
				col = float4(1, 0.5, 0.5, 0);
			}
		   ENDCG

		}


	}
		FallBack "Diffuse"
}
