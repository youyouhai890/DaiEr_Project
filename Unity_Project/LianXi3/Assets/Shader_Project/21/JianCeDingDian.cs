using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;

public class JianCeDingDian : MonoBehaviour {

   public MeshFilter mf;

	// Use this for initialization
	void Start () {
      
        Vector3[] vc3 = mf.mesh.vertices;  //获取顶点
        float max = vc3.Max(v=>v.x);    //获取最大值
        float min = vc3.Min(v=>v.x);    //获取最大值

        Debug.Log( "最大顶点(向量)-----" + max );
        Debug.Log( "最小顶点(向量)-----" + min );
	}
	
	// Update is called once per frame
	void Update () {
        //Y轴旋转
        transform.Rotate( Vector3.up , Time.deltaTime * 10 );
	}
}
