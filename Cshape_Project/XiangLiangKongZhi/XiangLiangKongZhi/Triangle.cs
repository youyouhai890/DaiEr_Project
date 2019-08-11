using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XiangLiangKongZhi
{
    //三角形
    class Triangle
    {
      //形成三角形的三个点
        PointF A, B, C;
        public  Triangle(PointF A,PointF B,PointF C)
        {
            this.A = A;
            this.B = B;
            this.C = C;
        }

        //被应用部分,画三角形
        public  void Draw(Graphics g)
        {
            //画笔
            Pen pen = new Pen( Color.Red , 2 );
            //画三角形
            g.DrawLine( pen , A , B );
            g.DrawLine( pen , B , C );
            g.DrawLine( pen , C , A );

        }

        //用矩阵(2D)旋转三角形的三个顶,点参数为一个圆的值
        public void Rotate(int degrees)
        {
         //获取某一个圆(对应传入参数的值的圆)的一个弧度单位 = 参数值(随意的) / 360度(圆) * π
            float angle = (float)( degrees / 360.0f * Math.PI );
          
         //旋转三角形的三个顶点中A点,最后把三个顶点连接起来成旋转后的三角形
            float newX = (float)( A.X * Math.Cos( angle ) - A.Y * Math.Sin( angle ) );
            float newY = (float)( A.X * Math.Sin( angle ) + A.Y * Math.Cos( angle ) );
            A.X = newX;
            A.Y = newY;


          //旋转三角形的三个顶点中B点,最后把三个顶点连接起来成旋转后的三角形
            newX = (float)( B.X * Math.Cos( angle ) - B.Y * Math.Sin( angle ) );
            newY = (float)( B.X * Math.Sin( angle ) + B.Y * Math.Cos( angle ) );
            B.X = newX;
            B.Y = newY;


          //旋转三角形的三个顶点中C点,最后把三个顶点连接起来成旋转后的三角形
            newX = (float)( C.X * Math.Cos( angle ) - C.Y * Math.Sin( angle ) );
            newY = (float)( C.X * Math.Sin( angle ) + C.Y * Math.Cos( angle ) );
            C.X = newX;
            C.Y = newY;


        }

    }
}
