Shader "Custom/jgt" {
	SubShader{
		pass
			{
			CGPROGRAM		//CG语句开头,类似main函数

			#pragma vertex vert			//类似宏定义
			#pragma fragment frag

			//定义结构体,要在应用之前定义
			struct JieGouTi
			{
				float4 pos : POSITION;
				float2 op : TEXCOORD0;
				float4 col : COLOR;
			};

			//从外部(Unity)传递的信息用inp结构体来接受
			struct inp
			{
				float4 ojpos:POSITION;
			};

			JieGouTi vert(inp input)
			{
				
				JieGouTi jgt;		//结构体的变量定义
				jgt.pos = input.ojpos;
				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jj) : COLOR
			{
				jj.col = jj.pos;
				return jj.col;
			}
				ENDCG
		}
	}
		FallBack "Diffuse"
}
