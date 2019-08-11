Shader "Custom/JiaoHu" {
		Properties {
			_Color ("Color", Color) = (1,1,1,1)		//定义shader里的属性(黑色),后面没有冒号
		}
	SubShader {
	pass {
			CGPROGRAM
			#pragma vertex vert			//类似宏定义
			#pragma fragment frag
			
				//定义结构体,要在应用之前定义
			struct JieGouTi
			{
				float4 pos : POSITION;
				float2 op : TEXCOORD0;
				float4 col : COLOR;
			};								
			struct inp
			{
				float4 ojpos:POSITION;
			};

			float4 _Color;	//在CG函数里面使用shader属性,必须重新定义一次
			uniform float4 two;		//获取从外部定义的变量
			
			JieGouTi vert(inp input)
			{
				JieGouTi jgt;		//结构体的变量定义
				jgt.pos = input.ojpos;
				return jgt;
			}
			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jj) : COLOR
			{
				//return _Color * two;
				//插值函数,第三个参数(1)限制在0～1之间。当t = 0返回_Color，当t = 1 返回two。当t = 0.5 返回_Color和two的平均值。
				return  lerp(_Color ,two,1);
			}
			ENDCG
	  }
	}
	FallBack "Diffuse"
}
