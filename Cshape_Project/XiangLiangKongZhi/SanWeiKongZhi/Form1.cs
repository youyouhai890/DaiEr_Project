using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SanWeiKongZhi
{
    public partial class Form1 : Form
    {
        int a;  //角度
        Triangle3D t;
        Matrix4x4 m_scale;  //缩放矩阵
        Matrix4x4 m_rotationX;  //缩放矩阵
        Matrix4x4 m_rotationY;  //缩放矩阵
        Matrix4x4 m_rotationZ;  //缩放矩阵
        Matrix4x4 m_view;  //摄像机矩阵
        Matrix4x4 m_projection;  //投影矩阵
        public Form1()
        {
            InitializeComponent();

            m_scale = new Matrix4x4();  //缩放矩阵
            m_scale[1 , 1] = 250;       
            m_scale[2 , 2] = 250;
            m_scale[3 , 3] = 250;
            m_scale[4 , 4] = 1;     //这个值如果为0,跟其他矩阵相乘后得到的值不准确


            m_view = new Matrix4x4();       //摄像机矩阵
            m_view[1 , 1] = 1;
            m_view[2 , 2] = 1;
            m_view[3 , 3] = 1;
            //要看到物体(三角形)所有顶点的话,正常摄像机应该放到物体-Z轴方向(-250)
            //但是这里取值250是因为物体变换过后的顶点位置,也就是物体的位置
            m_view[4 , 3] = 250;    //Z轴平移(可以想象成物体(三角形)在摄像机里平移)
            m_view[4 , 4] = 1;  //这个值如果为0,跟其他矩阵相乘后得到的值不准确


            m_projection = new Matrix4x4();     //投影矩阵(摄像机到屏幕,3D转2D)
            m_projection[1 , 1] = 1;
            m_projection[2 , 2] = 1;
            m_projection[3 , 3] = 1;
            //摄像机与小孔距离(小孔成像)250,小孔到投影面是250
            m_projection[3 , 4] = 1.0/250;  //第四列

            m_rotationX = new Matrix4x4();   //初始化旋转矩阵
            m_rotationY = new Matrix4x4();   //初始化旋转矩阵
            m_rotationZ = new Matrix4x4();   //初始化旋转矩阵 
        }
        
        //应用部分,-------从这里开始保存原始顶点
        private void Form1_Load( object sender , EventArgs e )
        {
            //初始化三角形的三个点(最初的点),最初特别小
            //,Vector4的最后一个分量1表示点(顶点),0的话表示分量,详细请看shader基础矩阵各种特性章节
          //在3D的矩阵空间里屏幕Y轴向上是取正值的,而屏幕里Y轴向上是负值,要以3D的为准所以这里取正值
            Vector4 a = new Vector4( 0 , 0.5 , 0 , 1 );
            Vector4 b = new Vector4( 0.5 , -0.5 , 0 , 1 );
            Vector4 c = new Vector4( -0.5 , -0.5 , 0 , 1 );
            //调用自定义的函数,把(顶点)存到原始顶点变量A,B,C
            t = new Triangle3D( a , b , c );

          //  t.Transform( m_scale ); //变换三角形顶点(缩放)

        }

        //应用部分,-------从这里开始绘制
        private void Form1_Paint( object sender , PaintEventArgs e )
        {
            t.Draw( e.Graphics );
        }

        private void timer1_Tick( object sender , EventArgs e )
        {
            a += 2; //每次增加2个角度
            double angle = a / 360.0 * Math.PI; //把角度变换为弧度
            
            //3D的X轴旋转矩阵
            m_rotationX[1 , 1] = 1;
            m_rotationX[2 , 2] = Math.Cos( angle );
            m_rotationX[2 , 3] = Math.Sin( angle );
            m_rotationX[3 , 2] = -Math.Sin( angle );
            m_rotationX[3 , 3] = Math.Cos( angle );
            m_rotationX[4 , 4] = 1;

            //3D的Y轴旋转矩阵公式
            m_rotationY[1 , 1] = Math.Cos( angle );
            m_rotationY[1 , 3] = Math.Sin( angle );
            m_rotationY[2 , 2] = 1;
            m_rotationY[3 , 1] = -Math.Sin( angle );
            m_rotationY[3 , 3] = Math.Cos( angle );
            m_rotationY[4 , 4] = 1;

            //3D的Z轴旋转矩阵公式
            m_rotationZ[1 , 1] = Math.Cos( angle );
            m_rotationZ[1 , 2] = Math.Sin( angle );
            m_rotationZ[2 , 1] = -Math.Sin( angle );
            m_rotationZ[2 , 2] = Math.Cos( angle );
            m_rotationZ[3 , 3] =1;
            m_rotationZ[4 , 4] = 1;

            if ( this.cbX.Checked ) //检测有没有选择复选框
            {
                //矩阵转置
                Matrix4x4 tx = m_rotationX.Transpose();
                //在源矩阵乘以源矩阵的转置得到逆矩阵
                m_rotationX = m_rotationX.Mul(tx);
            }

            if ( this.cbY.Checked ) //检测有没有选择复选框
            {
                //矩阵转置
                Matrix4x4 ty = m_rotationY.Transpose();
                //在源矩阵乘以源矩阵的转置得到逆矩阵
                m_rotationY = m_rotationY.Mul(ty);
            }

            if ( this.cbZ.Checked ) //检测有没有选择复选框
            {
                //矩阵转置
                Matrix4x4 tz = m_rotationZ.Transpose();
                //在源矩阵乘以源矩阵的转置得到逆矩阵
                m_rotationZ = m_rotationZ.Mul(tz);
            }
            //合并所有矩阵(功能融合)
            Matrix4x4 mall = m_rotationX.Mul( m_rotationY.Mul( m_rotationZ ) );
           // Matrix4x4 mall = m_rotationZ.Mul( m_rotationY.Mul( m_rotationX ) );

            //缩放矩阵 * 旋转矩阵  获得包含这两个功能的矩阵
            Matrix4x4 m = m_scale.Mul( mall );    //目前位置m是模型到世界变换的矩阵

            //t.Transform( m );   //缩放矩阵变换后已经是世界空间
            //t.CalculateNormal();    //法向量计算

            //m为任意矩阵相乘后的矩阵(用于世界空间) , 第二个参数为光线照射位置(可判定在屏幕外)
            t.CalculateLighting(m,new Vector4(-1,1,-1,0));

            Matrix4x4 mv = m.Mul( m_view );    //世界到摄像机
            Matrix4x4 mvp = mv.Mul( m_projection );  //摄像机到投影
             t.Transform( mvp );    //变换三角形顶点(mvp矩阵变换)
             this.Invalidate(); //失效重画
        }


        private void trackBar2_Scroll( object sender , EventArgs e )
        {
                        //调整摄像机到对象之间的距离(平移)
            m_view[4 , 3] = ( sender as TrackBar ).Value;
        }
    }
}
