using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load( object sender , EventArgs e )
    {
    }

    protected void Button1_Click( object sender , EventArgs e )
    {
       // BoFangYinPin();
       // XiaZai();
       // BoFangDianYing();
        BoFangFlash();
    }

    void BoFangYinPin()
    {
          Response.Write("<embed src = 'ShengMing.mp3' width = '0' height = '0' id = 'music' autostart = 'true'></embed>");

    }

    void XiaZai()
    {
        string path =Server.MapPath( "\\ZiMuLu\\ShengMing.mp3");
        Response.Write( path );

          FileInfo fileInfo = new FileInfo(path);
          Response.Clear();
          Response.ClearContent();
          Response.ClearHeaders();

          //显示在下面窗口的中文文件名

          // HttpUtility.HtmlEncode ： 将字符串转换为 HTML 编码的字符串。
          Response.AddHeader("Content-Disposition", "attachment;filename=" +HttpUtility.UrlEncode("bbb.mp3"));
          Response.AddHeader("Content-Length", fileInfo.Length.ToString());
          Response.AddHeader("Content-Transfer-Encoding", "binary");
          Response.ContentType = "application/octet-stream;charset=gb2312";
         // Response.ContentType = checktype(HttpUtility.UrlEncodeUnicode(fileExt));//"application/octet-stream";
          Response.ContentEncoding = System.Text.Encoding.GetEncoding("gb2312");
          Response.WriteFile(fileInfo.FullName);
          Response.Flush();
          Response.End();
    }


    public  string DianYingWenJian;
    void BoFangDianYing()
    {
        //string path =Server.MapPath( "ZiMuLu\\DianYing.mp4");
      string path ="ZiMuLu\\DianYing.mp4";
      string path2 ="23873.swf";

     DianYingWenJian = path;
         Response.Write(
         "<video src=\"" + path + "\" controls=\"controls\" width=\"300\" height=\"200\"></video>"
         );
    }

    void BoFangFlash()
    {
        string path ="ZiMuLu\\flashDongHua\\flash\\23873.swf";
              //Flash对象
        StringBuilder sb = new StringBuilder();
        sb.AppendFormat("<object classid='clsid:D27CDB6E-AE6D-11cf-96B8-444553540000' codebase='http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=7,0,19,0'width='{0}' height='{1}'>", 500, 500);
        sb.AppendFormat("<param name='movie' value='{0}'>", path);
        sb.AppendFormat("<param name='quality' value='high'>");
        sb.AppendFormat("<param name='AutoStart' value='1'>");
        sb.AppendFormat("<embed src='{0}' quality='high' pluginspage='http://www.macromedia.com/go/getflashplayer' type='application/x-shockwave-flash' width='{1}' height='{2}'></embed>",path,500,500);
        sb.Append("</object>");
        Response.Write(sb.ToString());
    }
}