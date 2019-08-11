using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
     
    public static int POINTCNT=6;   

    protected void Page_Load( object sender , EventArgs e )
    {
        if ( !IsPostBack )
        {
            fun();
            Response.Write( "是第一次执行-----------" );
           Label1.Text = DateTime.Now.ToLongTimeString();
          //UpdatePanel1.Update();


        }
        else
        {
            Response.Write( "不是第一次执行==========" );
        }

    }


     protected void Timer1_Tick( object sender , EventArgs e )
    {
                 Label1.Text = DateTime.Now.ToLongTimeString();
         //Label2.Text = DateTime.Now.ToLongTimeString();
         fun();
       // UpdatePanel1.Update();
        //UpdatePanel2.Update();
    }



    public void fun()
    {
        //绘制边框一般以Draw...开头 , 填充内部一般以Fill...开头

        //画椭圆形
        //Bitmap bitm = new Bitmap( 300 , 150 );
        //Graphics g = Graphics.FromImage( bitm );
        //g.Clear( Color.YellowGreen );
        //Font font1 = new Font( "宋体" , 12 );
        //Brush bru = new SolidBrush( Color.Blue );   //画刷
        //Pen mpen = new Pen( Color.Blue , 5 );   //画笔
        //g.DrawString( "GDI+中单色画刷的应用",font1,bru,80,5 );

        //SolidBrush mysolbru = new SolidBrush( Color.Green );
        //g.FillEllipse( mysolbru , 20 , 20 , 220 , 120 );  //椭圆形
        //System.IO.MemoryStream ms = new System.IO.MemoryStream();
        //bitm.Save( ms , System.Drawing.Imaging.ImageFormat.Gif );
        //Response.ClearContent();
        //Response.ContentType = "image/gif";
        //Response.BinaryWrite( ms.ToArray() );

        ////////////////////////////////////////////////////////////////
        //画直线
        //Bitmap bitm = new Bitmap( 200 , 150 );  //创建位图
        //Graphics g = Graphics.FromImage( bitm ); //创建画布
        //g.Clear( Color.WhiteSmoke );    //清空背景色
        //Pen p = new Pen( Color.Blue , 2 );  //创建画笔
        //g.DrawLine( p , 20 , 30 , 120 , 30 );   //绘制直线
        //System.IO.MemoryStream ms = new System.IO.MemoryStream();   //内存流
        //bitm.Save( ms , System.Drawing.Imaging.ImageFormat.Gif );   //将图像保存到流中
        //Response.ClearContent();    //清除缓存区中所有内容
        //Response.ContentType = "image/gif"; //设置输出图片类型
        //Response.BinaryWrite( ms.ToArray() );   //写入HTTP流输出到页面上


        ////////////////////////////////////////////////////////////////

        //int KuanDu = 380, GaoDu = 200;
        //Bitmap bitm = new Bitmap( KuanDu , GaoDu );  //创建位图
        //Graphics g = Graphics.FromImage( bitm ); //创建画布

        //try
        //{
        //    //绘制边框一般以Draw...开头 , 填充内部一般以Fill...开头

        //    g.Clear( Color.YellowGreen );    //清空背景色
        //    Font font1 = new Font( "宋体" , 12 );
        //    Brush bru1 = new SolidBrush( Color.Black );   //画刷
        //    Brush bru2 = new SolidBrush( Color.Brown );   //画刷
        //    g.DrawString( "绘制带阴影效果的矩形" , font1 , bru1 , 80 , 20 );
        //    g.FillRectangle( bru1 , 80 , 60 , 200 , 100 );  //矩形
        //    g.FillRectangle( bru2 , 75 , 55 , 200 , 100 );
        //    System.IO.MemoryStream ms = new System.IO.MemoryStream();
        //    bitm.Save( ms , System.Drawing.Imaging.ImageFormat.Gif );
        //    Response.ClearContent();    //清除缓存区中所有内容
        //    Response.ContentType = "image/gif"; //设置输出图片类型
        //    Response.BinaryWrite( ms.ToArray() );   //写入HTTP流输出到页面上



        //}
        //catch ( Exception )
        //{

        //    throw;
        //}


        ////////////////////////////////////////////////////////////

        //Bitmap bitm = new Bitmap( 500 , 500 );  //创建位图
        //Graphics g = Graphics.FromImage( bitm ); //创建画布
        //g.Clear( Color.WhiteSmoke );    //清空背景色
        //Font font1 = new Font( "宋体" , 12 );
        //Brush bru1 = new SolidBrush( Color.Black );   //画刷
        //Pen p = new Pen( Color.Blue , 2 );  //创建画笔
        //g.DrawString( "绘制椭圆,弧形和扇形" , font1 , bru1 , 80 , 20 );
        ////矩形区域,用来画图形
        //Rectangle[] rects = {new Rectangle(10,50,80,100)
        //                   ,new Rectangle(170,110,250,150)
        //                   ,new Rectangle(80,220,220,220)
        //                  };
        //g.DrawEllipse( p , rects[0] );      //绘制椭圆,边框类型用Draw开头的,填充型用Fill开头的
        //p.Color = Color.Blue;
        //g.DrawArc( p , rects[1] , -180 , 90 );      //绘制圆形
        //p.Color = Color.Blue;
        //g.DrawPie( p , rects[2] , -180 , -150 );      //绘制扇形
        //p.Color = Color.Blue;

        //System.IO.MemoryStream ms = new System.IO.MemoryStream();
        //bitm.Save( ms , System.Drawing.Imaging.ImageFormat.Jpeg );//将图片格式保存到内存流中
        //Response.ClearContent();    //清除缓存区中所有内容
        //Response.ContentType = "image/Jpeg"; //设置输出图片类型
        //Response.BinaryWrite( ms.ToArray() );   //写入HTTP流输出到页面上


        //////////////////////////////////////////////////////////////
        //int KuanDu = 440, GaoDu = 200;
        //Bitmap bitm = new Bitmap( KuanDu , GaoDu );  //创建位图
        //Graphics g = Graphics.FromImage( bitm ); //创建画布

        //try
        //{
        //    //绘制边框一般以Draw...开头 , 填充内部一般以Fill...开头

        //    g.Clear( Color.YellowGreen );    //清空背景色
        //    Font font1 = new Font( "宋体" , 12 );
        //    Brush bru1 = new SolidBrush( Color.Black );   //画刷
        //    Pen p = new Pen( Color.Blue , 2 );  //创建画笔
        //    g.DrawString( "绘制多边形" , font1 , bru1 , 100 , 20 );
        //    Point[] poi = new Point[6];
        //    poi[0].X = 280; poi[0].Y = 60;        //多边形的点
        //    poi[1].X = 250; poi[1].Y = 110;     //中间点(上下点之间)Y轴 60+(160-60)/2
        //    poi[2].X = 280; poi[2].Y = 160;
        //    poi[3].X = 350; poi[3].Y = 160;
        //    poi[4].X = 380; poi[4].Y = 110;     //中间点(上下点之间)Y轴  60+(160-60)/2
        //    poi[5].X = 350; poi[5].Y = 60;
        //    g.DrawPolygon( p , poi );   //绘制多边形
        //    System.IO.MemoryStream ms = new System.IO.MemoryStream();
        //    bitm.Save( ms , System.Drawing.Imaging.ImageFormat.Gif );
        //    Response.ClearContent();    //清除缓存区中所有内容
        //    Response.ContentType = "image/gif"; //设置输出图片类型
        //    Response.BinaryWrite( ms.ToArray() );   //写入HTTP流输出到页面上


        //}
        //catch ( Exception )
        //{

        //    throw;
        //}


        ////////////////////////////////////////////////////////////////////


        //类似于#define宏定义，设置三个常量
        //int POINTC POINTCNT;

        if ( POINTCNT > 30 )
        {
            POINTCNT = POINTCNT % 6;
        }
          POINTCNT = POINTCNT + 2;
      //  POINTCNT = Convert.ToInt32( Application["key"].ToString()) + 2;
        int XMAX = 300;//X轴最大值(总距离)，也就是2π对应的值(应该是可以看作两个圆的周长)  
        int XMIN = 0;//X轴最小值

        //声明坐标点数组
        Point[] point = new Point[POINTCNT];
        //放大倍数,2 * PI应该是360度,所以应该是一个圆,这里求的应该是两个PI(一个圆)平均长度-1(不到一个圆的平均长)
        double times = ( XMAX - XMIN ) / ( 2 * Math.PI - 1 );
        //i增量对应的point.X增量(应该是X轴平均距离)
        double PingJunJuLi = ( XMAX - XMIN ) / ( POINTCNT - 1 );    //这里奇数会报错,因为变成偶数

        for ( int i = 0 ; i < POINTCNT ; i++ )
        {
            point[i].X = (int)( i * PingJunJuLi );//每个点的x轴按照平均距离递增
            point[i].Y = (int)( times * Math.Sin( point[i].X / times ) );//sin(2π=总长度/半径(稍微短))
            point[i].Y = (int)( point[i].Y + times * 2 );//Y轴向上或向下平移，即1*times，令最高点（也就是3π/2对应的-1点）的值为0

        }

        //图片之间的类型转换(bit->image)
        Bitmap bitm = new Bitmap( 500 , 500 );  //创建位图
        Graphics g = Graphics.FromImage( bitm ); //创建画布
        g.Clear( Color.YellowGreen );    //清空背景色
        Font font1 = new Font( "宋体" , 12 );
        Brush bru1 = new SolidBrush( Color.Black );   //画刷
        g.DrawString( "POINTCNT------" + POINTCNT.ToString() , font1 , bru1 , 100 , 200 );
        g.DrawString( "times------" + times.ToString() , font1 , bru1 , 100 , 220 );
        g.DrawString( "PingJunJuLi------" + PingJunJuLi.ToString() , font1 , bru1 , 100 , 240 );
        g.DrawString( "Math.PI------" + Math.PI.ToString() , font1 , bru1 , 100 , 260 );
        g.DrawString( "Math.Sin(point[0].X / times)------" + Math.Sin( point[0].X / times ).ToString() , font1 , bru1 , 100 , 280 );
        g.DrawString( "Math.Sin(point[1].X / times)------" + Math.Sin( point[1].X / times ).ToString() , font1 , bru1 , 100 , 300 );
        g.DrawString( "Math.Sin(point[2].X / times)------" + Math.Sin( point[2].X / times ).ToString() , font1 , bru1 , 100 , 320 );
        Pen p = new Pen( Color.LightGoldenrodYellow , 2 );//画笔
        g.DrawLines( p , point );//多点绘图，直线连接


        System.IO.MemoryStream ms = new System.IO.MemoryStream();
        bitm.Save( ms , System.Drawing.Imaging.ImageFormat.Gif );
        string base64 = Convert.ToBase64String(ms.ToArray());
        Image1.ImageUrl = "data:image/png;base64,"+base64;  //存放到控件

        //Response.ClearContent();    //清除缓存区中所有内容
        //Response.ContentType = "image/gif"; //设置输出图片类型
        //Response.BinaryWrite( ms.ToArray() );   //写入HTTP流输出到页面上
        g.Dispose();

    }






    protected void Button1_Click( object sender , EventArgs e )
    {
           fun();
           Label1.Text = DateTime.Now.ToLongTimeString();

    }


}