using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShiXianZhiHuan : MonoBehaviour {

	// Use this for initialization
	void Start () {

        //设置替换的shader函数,第一个参数为要替换的shader文件 , 第二个参数为要替换的shader标签
        Camera.main.SetReplacementShader( Shader.Find( "Custom/ZhiHuan" ) , "rendertype" );
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
