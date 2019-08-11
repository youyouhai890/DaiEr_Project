using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LiFangTi
{
    class Cube
    {
        //构成立方体12个面的所有点
        //立方体上面四个点
        Vector4 a = new Vector4( -0.5 , 0.5 , 0.5 , 1 );
        Vector4 b = new Vector4( 0.5 , 0.5 , 0.5 , 1 );
        Vector4 c = new Vector4( 0.5 , 0.5 , -0.5 , 1 );
        Vector4 d = new Vector4( -0.5 , 0.5 , -0.5 , 1 );
        //立方体下面四个点
        Vector4 e = new Vector4( -0.5 ,-0.5 , 0.5 , 1 );
        Vector4 f = new Vector4( 0.5 , -0.5 , 0.5 , 1 );
        Vector4 g = new Vector4( 0.5 , -0.5 , -0.5 , 1 );
        Vector4 h = new Vector4( -0.5 ,-0.5 , -0.5 , 1 );
        //构成立方体的所有三角形,总共12个
        private Triangle3D[] triangels = new Triangle3D[12];


        public Cube()
        {
            //顶面两个三角形,可以看到的面所以顺时针(顺时针)方向
            triangels[0] = new Triangle3D( a , b , c );
            triangels[1] = new Triangle3D( a , c , d );

            //下面两个三角形,不能看到所以逆时针(左右坐标)方向
            triangels[2] = new Triangle3D( e , h , f );
            triangels[3] = new Triangle3D( f , h , g );

            //正面 , 顺时针方向
            triangels[4] = new Triangle3D( d , c , g );
            triangels[5] = new Triangle3D( d , g , h );

            //背面,逆时针方向
            triangels[6] = new Triangle3D( a , e , b );
            triangels[7] = new Triangle3D( b , e , f );

            //右面,顺时针方向
            triangels[8] = new Triangle3D( b , f , c );
            triangels[9] = new Triangle3D( c , f , g );

            //左面,逆时针
            triangels[10] = new Triangle3D( a , d , h );
            triangels[11] = new Triangle3D( a , h , e );

        }
        public void Transform(Matrix4x4 m )
        {
            //遍历所有三角形的顶点
            foreach ( Triangle3D t in triangels )
            {
                t.Transform( m );
            }
        }
        public void CalculateLighting(Matrix4x4 _ObjectToWorld,Vector4 L)
        {
           //遍历所有三角形,变换到世界坐标,计算法向量,计算光照强度(面着色),计算背面剔除
            foreach ( Triangle3D t in triangels )
            {
                t.CalculateLighting( _ObjectToWorld,L );
            }
        }  
        public void Draw(Graphics g ,bool isLine)   //isLine为自定义的bool型(是否显示线框)
        {
           g.TranslateTransform( 300 , 300 );  //移动中心

            //遍历所有三角形,绘制所有三角形
            foreach ( Triangle3D t in triangels )
            {
                t.Draw(g,isLine);
            }
        }




    }
}
