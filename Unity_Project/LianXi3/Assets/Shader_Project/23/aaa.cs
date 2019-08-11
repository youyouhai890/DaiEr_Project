using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class aaa : MonoBehaviour {

    public float PingYi_x;
    public float PingYi_y;
    public float PianYi_x;
    public float PianYi_y;



	// Use this for initialization
	void Start () {

	}
	
	// Update is called once per frame
	void Update () {
		        //跟shader交互
        GetComponent<Renderer>().material.SetFloat( "PingYi_x" ,PingYi_x );
        GetComponent<Renderer>().material.SetFloat( "PingYi_y" ,PingYi_y );
        GetComponent<Renderer>().material.SetFloat( "PianYi_x" ,PianYi_x );
        GetComponent<Renderer>().material.SetFloat( "PianYi_y" ,PianYi_y );
	}
}
