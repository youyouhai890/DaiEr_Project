using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class AssBunl /*: MonoBehaviour*/ {  //不用挂到对象上面

    [MenuItem("打包/开始打包")]
    static void Assbun()
    {
        Debug.Log( "开始打包..." );

        //在场景中选择的对象
        Object[] gameObjs = Selection.GetFiltered( typeof( Object ) , SelectionMode.Unfiltered );


        foreach ( var item in gameObjs )    //遍历对象
        {
            //获取路径
             string HuoQuLuJing = AssetDatabase.GetAssetPath( item );
            //    Debug.Log( "获取路径-----"+HuoQuLuJing );

            string CunFangLuJing = Application.dataPath+"/Resources/YuZhiTi";
               Debug.Log("存放路径-----"+ CunFangLuJing );

            //AssetBundle打包函数
            if ( BuildPipeline.BuildAssetBundles( CunFangLuJing , BuildAssetBundleOptions.None , BuildTarget.StandaloneWindows64 ) )
            {
                Debug.Log( "打包成功" );

            }
            else
            {
                Debug.Log( "打包失败" );
            }

        }
        AssetDatabase.Refresh();    //刷新

    }

}
