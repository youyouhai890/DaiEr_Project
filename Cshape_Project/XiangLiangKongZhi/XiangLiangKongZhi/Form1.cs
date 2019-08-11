using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace XiangLiangKongZhi
{
    public partial class Form1 : Form
    {
        //三角形类
        Triangle t;

        //int degrees=1;

        public Form1()
        {
            InitializeComponent();
        }

          
        private void Form1_Paint( object sender , PaintEventArgs e )
        {
            //把三角形的中心点移动到画布中心
            e.Graphics.TranslateTransform( 300 , 250 );
            //调用函数Draw(画三角形)
            t.Draw( e.Graphics );
        }

         //最初开始应用部分
        private void Form1_Load( object sender , EventArgs e )
        {
            //应该时窗口加载时调用的回调函数
            //最初用三个顶点初始化三角形
            PointF A = new PointF( 0 , -200 );
            PointF B = new PointF( 200 , 200 );
            PointF C = new PointF( -200 , 200 );
            t = new Triangle( A , B , C );
        }

        private void timer1_Tick( object sender , EventArgs e )
        {
            //degrees++;
           // t.Rotate( degrees );
            //调用函数(参数为某个圆的值(应该是周长))
            t.Rotate( 1 );

            //失效(类似刷新),当画布失效以后重新绘制
            this.Invalidate();

        }

    }
}
