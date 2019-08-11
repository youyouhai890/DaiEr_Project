
Shader "Custom/boHanShu" {
	Properties {
		_MainTex("纹理", 2D) = "white" {}
	_F("倍数",range(1,30)) = 10
		_A("衰减",range(0,0.1)) = 0.01
		_R("半径",range(0,1)) = 0

	//_uv("uv",range(-0.009,0.009))=0
	}
		SubShader{
				pass {
				CGPROGRAM
	#pragma vertex vert			//类似宏定义
	#pragma fragment frag
	#include "unitycg.cginc"	//导入引擎库

			sampler2D _MainTex;
			float _uv;
			float4 _MainTex_ST;	//_MainTex_ST为Unity里的内置变量,可自动获取平移和偏移的数据
			float _F;
			float _A;	//衰减
			float _R;
			
			struct JieGouTi
			{
				float4 pos : POSITION;
				float2 uv : TEXCOORD0;
				float2 uv2 : TEXCOORD1;
			};

			//参数是引擎库自带的结构体
			JieGouTi vert(appdata_full inp)
			{
				JieGouTi jgt;
				//把模型空间转换为世界空间
				jgt.pos = UnityObjectToClipPos(inp.vertex);

				//_MainTex_ST为Unity里平移和偏移的内置变量,_MainTex_ST.xy为平移,_MainTex_ST.zw偏移
				 //jgt.uv = inp.texcoord.xy * _MainTex_ST.xy + _MainTex_ST.zw;
				//调用内置的宏(获取uv)
				jgt.uv = TRANSFORM_TEX(inp.texcoord, _MainTex);

				return jgt;
			}

			//接受片段程序返回的COLOR语义的值
			fixed4 frag(JieGouTi jgt) :COLOR
			{
				//可理解为缩放(平铺)
				//jgt.uv.x *= _Time.x;
				//可理解为偏移
				//jgt.uv.x += _Time.x;
				//xy轴偏移
				// jgt.uv += _Time.x;

				//对于片段程序uv的x值每次都是一样的所以图片不会动, 如果没有0.01,值范围可能超过1(uv值范围)
				//jgt.uv.x += 0.01 * sin(jgt.uv.x );

				//如果没有0.01(波幅度),值范围可能超过1 , sin()的值范围是-1到1, 3.14可能是用于不规则变化(圆),10是倍数 , _time.y是变化因子
				//jgt.uv.x += 0.01 * sin(jgt.uv.x*3.14*_F + _Time.y);
				//jgt.uv.y += 0.01 * sin(jgt.uv.y*3.14*_F +_Time.y);
				//效果同上面的两行叠加
				jgt.uv += _A * sin(jgt.uv * 3.14 * _F + _Time.y);

				float2 uv = jgt.uv;
				//2维向量距离公式 = 根(  (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) 
				//计算每个uv到中心点(uv中心点)距离,distance为计算距离的函数,类似于length()函数
				float JuLi = distance(uv, float2(0.5, 0.5));	//返回的范围应该是0到1
				float BiLi=0 ;
				//if (JuLi < _R) {	//距离小于半径 
					//saturate替代了if语句
					_A *= saturate(1 -JuLi / _R);	//JuLi/_R为距离的值越接近半径 值越大,超过半径时大于1,在取反(-1)后衰减度_A的值很小
					 BiLi = _A * sin(-JuLi * 3.14 * _F + _Time.y);	//sin()的值范围是-1到1,所以BiLi也有可能有负数,_A为衰减度

					uv = uv + uv *BiLi;
				//}



				//float bl = step(uv.x,0.5);
				//把输出的BiLi作为有颜色区分开来显示,  由于BiLi可能有负值所以控制范围(saturate)0到1 , 100是倍数(高亮)
				fixed4 col = tex2D(_MainTex, uv) +fixed4(1, 1, 1, 1) * saturate(BiLi) * 100;
				//fixed4 col = tex2D(_MainTex, uv) + fixed4(1, 1, 1, 1) * saturate(bl) * 100;

				//从纹理坐标采样(可理解为贴图)
				//float4 col = tex2D(_MainTex,jj.uv);
				//float4 col = tex2D(_MainTex, uv);

				return col;
			}

				ENDCG
		}
	}
	FallBack "Diffuse"
}
