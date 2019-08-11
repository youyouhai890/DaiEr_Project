using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class mvp : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {

        //旋转矩阵,注意C#里的矩阵下标是从0开始
        Matrix4x4 rm = new Matrix4x4();
        rm[0 , 0] = Mathf.Cos( Time.realtimeSinceStartup );
        rm[0 , 2] = Mathf.Sin( Time.realtimeSinceStartup );
        rm[1 , 1] = 1;
        rm[2 , 0] = -Mathf.Sin( Time.realtimeSinceStartup );
        rm[2 , 2] = Mathf.Cos( Time.realtimeSinceStartup );
        rm[3 , 3] = 1;

        //缩放矩阵,注意C#里的矩阵下标是从0开始
        Matrix4x4 SuoFang = new Matrix4x4();
        SuoFang[0 , 0] = Mathf.Sin( Time.realtimeSinceStartup );
        SuoFang[1 , 1] = Mathf.Cos( Time.realtimeSinceStartup );
        SuoFang[2 , 2] = Mathf.Sin( Time.realtimeSinceStartup );
        SuoFang[3 , 3] = 1;


        //获取mvp矩阵,注意乘法顺序会导致结果出错 , MVP = 摄像机空间到投影(小孔成像)矩阵 *  世界空间到摄像机空间矩阵 * 当前模型空间到世界空间矩阵
        Matrix4x4 mvp = Camera.main.projectionMatrix * Camera.main.worldToCameraMatrix * transform.localToWorldMatrix *SuoFang;
       // Matrix4x4 mvp =   transform.localToWorldMatrix* Camera.main.worldToCameraMatrix*Camera.main.projectionMatrix ;

        GetComponent<Renderer>().material.SetMatrix( "mvp" , mvp );

	}
}
