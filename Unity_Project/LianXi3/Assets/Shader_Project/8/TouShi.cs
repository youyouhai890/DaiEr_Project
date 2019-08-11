using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TouSHi : MonoBehaviour {


    private float dis = -1; //初始位置,屏幕左边
    private float r = 0.1f; //初始位置开始后的半径

	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
        dis += Time.deltaTime * 0.1f;   //速度降到10倍
        GetComponent<Renderer>().material.SetFloat( "dis" , dis );
        GetComponent<Renderer>().material.SetFloat( "r" , r );
	}
}
