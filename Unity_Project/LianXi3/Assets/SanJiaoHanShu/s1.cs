using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class s1 : MonoBehaviour {

    public Transform obj;
	// Use this for initialization
	void Start () {
        DrawCircle();
	}
	
	// Update is called once per frame
	void Update () {
		
	}


      void DrawCircle()
    {
        float x = obj.transform.localPosition.x;
        float y = obj.transform.localPosition.y;
        
        //半径
        float radir = 6;
        for (int i = 0; i < 1; i++)
        {
            //第一象限,(Mathf.PI / 180)等于一个弧度(弧度为一)单位
            Vector3 vc = Vector3.zero;
            vc.x = x + radir * Mathf.Cos( (Mathf.PI / 180) * i );
            vc.y = y + radir * Mathf.Sin( (Mathf.PI / 180) * i );
            GameObject tmpObj = Instantiate( obj.gameObject );
            tmpObj.transform.parent = obj.transform.parent;
            tmpObj.transform.localPosition = vc;
            tmpObj.transform.localScale = Vector3.one;






            //第四象限
            vc.y = y - radir * Mathf.Sin( Mathf.PI / 180 * i );
            tmpObj = Instantiate( obj.gameObject );
            tmpObj.transform.parent = obj.transform.parent;
            tmpObj.transform.localPosition = vc;
            tmpObj.transform.localScale = Vector3.one;
            ////第二象限
            //vc = Vector3.zero;
            //vc.x = x - radir * Mathf.Cos( Mathf.PI / 180 * i );
            //vc.y = y + radir * Mathf.Sin( Mathf.PI / 180 * i );
            //tmpObj = Instantiate( obj.gameObject );
            //tmpObj.transform.parent = obj.transform.parent;
            //tmpObj.transform.localPosition = vc;
            //tmpObj.transform.localScale = Vector3.one;

            ////第三象限
            //vc.y = y - radir * Mathf.Sin( Mathf.PI / 180 * i );
            //tmpObj = Instantiate( obj.gameObject );
            //tmpObj.transform.parent = obj.transform.parent;
            //tmpObj.transform.localPosition = vc;
            //tmpObj.transform.localScale = Vector3.one;

        }
 
    }

}
