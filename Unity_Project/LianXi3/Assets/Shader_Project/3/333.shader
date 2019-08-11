Shader "Custom/333" {
	SubShader{
			pass
		{

			CGPROGRAM		//CG语句开头,类似main函数

			#pragma vertex vert			//类似宏定义
			#pragma fragment frag





			float4 vert(in float2 ojPos:POSITION,out float4 pos : POSITION ,out float2 op:TEXCOORD0) :COLOR	//后面的COLOR代表返回值的语义
			{
				//out的POSITION只能有一个,多个out时可以用TEXCOORD0(范围为0到7)的变量把值传递到片段程序
				op = ojPos;	//ojPos为模型的坐标(x,y)
				pos = float4(ojPos,0.5, 0.5);
				return pos;
			}


			//接受片段程序返回的COLOR语义的值
			fixed2 frag(in float4 c:COLOR ,in float2 opp: TEXCOORD0) :COLOR
			{
			
				opp.y = 0.5;
				return opp;
			}


		ENDCG

		}

	}
		FallBack "Diffuse"

}
