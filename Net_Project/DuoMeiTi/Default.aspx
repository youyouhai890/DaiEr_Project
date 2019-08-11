<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>
<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        #mediaplayer {
            height: 223px;
            width: 398px;
        }
    </style>

</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <p><br />
          <a href="Resource.html" target="_blank">资源.html</a><br />
          <br />
          <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Button" />        
          <br />
          <br />
          <br />
          <%--<embed src="<%=url%>" width="300"autostart="true' height="45" type="audio/x-pn-realaudio-plugin"> 111</embed>--%>
          <%--<audio src="<%=url%>"></audio>--%>
          <audio id="aa" src="/ZiMuLu/ShengMing.mp3" controls>
            Your browser does not support the audio element.
          </audio>
          <br />
          
          <%--codebase为引用的播放器地址--%>
          <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
      codebase="http://fpdownload.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=7,0,0,0"
     width="300" height="200" id="Object1" align="center">
            <param name="allowScriptAccess" value="sameDomain" />
            <param name="movie" value="ZiMuLu/Flvplayer.swf" />
            <param name="quality" value="high" />
            <param name="bgcolor" value="#000088" />
            <embed src="ZiMuLu/Flvplayer.swf"
         quality="high" bgcolor="#000080" width="556" height="380"
         name="mymovie" align="center" allowscriptaccess="sameDomain" type="application/x-shockwave-flash"
         pluginspage="http://www.macromedia.com/go/getflashplayer" />     
          </object>
          
        </p>
        <p><a href="https://pan.baidu.com/s/1IKILdjLmAW2ZoYDP4no-7g">https://pan.baidu.com/s/1IKILdjLmAW2ZoYDP4no-7g</a></p>
        <p>&nbsp;</p>
    </div>
    </form>
</body>
</html>
