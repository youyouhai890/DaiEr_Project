using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class JH : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {

        //从外部定义传到shader里的四阶向量值
        GetComponent<Renderer>().material.SetVector( "two" , new Vector4( 0 , 1 , 0 , 1 )); //绿色
	}
}
