using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SanWeiKongZhi
{
    class Triangle3D
    {
        //存储变换过后的顶点
        private Vector4 a, b, c;
        //存储原始的顶点
        public Vector4 A, B, C;

        //private Vector4 normal; //法向量
        private bool cullBack;

        private float dot;  

        public Triangle3D() { }

        //把参数(顶点)存到原始顶点变量A,B,C
        public Triangle3D(Vector4 a,Vector4 b,Vector4 c)
        {
            this.A = this.a =  new Vector4( a );
            this.B = this.b =  new Vector4( b );
            this.C = this.c =  new Vector4( c );
        }

        //三角形利用矩阵的乘法进行变换顶点
        public void Transform(Matrix4x4 m)
        {
            this.a = m.Mul( this.A );
            this.b = m.Mul( this.B );
            this.c = m.Mul( this.C );
        }

        //光照计算(需要光向量和法线的点积(dot))
        //第一个参数是世界空间的矩阵,第二个参数是光向量的位置
        public void CalculateLighting(Matrix4x4 _ObjectToWorld,Vector4 L)   
        {
            this.Transform(_ObjectToWorld);  //三角形利用矩阵的乘法进行变换顶点位置
            Vector4 U = this.b - this.a;
            Vector4 V = this.c - this.a;
           Vector4 normal = U.Cross( V );

            //获取点积值用于面的光照计算, 规范化后的法线 * 规范化后的光线
            dot = normal.Normalized.Dot( L.Normalized );
            //dot值的范围控制,最大为dot
            dot = Math.Max( 0 , dot );

            //视向量,可以理解为眼睛,也是摄像机(这里已经是单位,所以不用规范化,实际用的时候按照情况需要规范化)
            Vector4 E = new Vector4( 0 , 0 , -1 , 0 );
            //剔除,如果点积(dot)值小于0说明摄像机和法向量超过了90度(可以剔除),如果介于0到1之间不能剔除(false)
            cullBack = normal.Normalized.Dot( E ) < 0 ? true : false;
        }


        public void Draw(Graphics g)
        {
            g.TranslateTransform( 300 , 300 );  //三角形中心点移动到屏幕中间
            //画边缘线,把多个点用直线连接起来
            g.DrawLines( new Pen( Color.Red , 2 ) , this.Get2DPointFArr() );
            //检测是否剔除(是否绘制实心,绘制面)
            if ( !cullBack )
            {
                GraphicsPath path = new GraphicsPath();
                path.AddLines( this.Get2DPointFArr() );

                //可以理解为颜色的每个分量值
                int r = (int)( 200 * dot )+55;  //防止值变为0所以后面加55
                Color color = Color.FromArgb( r , r , r );  //r,g,b颜色值
                Brush br = new SolidBrush( color );
                g.FillPath(br,path ); //填充面的颜色
            }

            



        }

        //绘制三角形
        private PointF[] Get2DPointFArr()
        {
            //要绘制三角形总共需要四个点
            PointF[] arr = new PointF[4];
            arr[0] = Get2DPointF( this.a ); //把3D顶点变换成2D顶点投影到屏幕
            arr[1] = Get2DPointF( this.b );
            arr[2] = Get2DPointF( this.c );
            arr[3] = arr[0];    //用来闭合最后两个点

            return arr;
        }

        //投影算法(把3D顶点变换成2D顶点投影到屏幕),详情看矩阵各种特性章节
        private PointF Get2DPointF(Vector4 v)
        {
            PointF p = new PointF();

            //投影算法(近大远小),把3D物体投影到2D屏幕
            //在3D的矩阵空间里屏幕Y轴向上是取正值的,而屏幕里Y轴向上是负值
            //所以3D要在屏幕里显示Y轴向上是取反(-)
            p.X = (float)( v.x / v.w );
            p.Y = -(float)( v.y / v.w );
            return p;
        }

    }
}
