using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Xml.Linq;
using System.Threading;
using System.Configuration;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load( object sender , EventArgs e )
    {
        //int[] arr = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 };

        ////这里vv应该是结果集(自定义的变量)
        //var value = from vv in arr
        //            where vv < 5 && vv > 2
        //            orderby vv descending
        //            select vv;

        //foreach ( var item in value )
        //{
        //    Response.Write( item + "<br>" );
        //}
        // LinqDBDataContext ldc = new LinqDBDataContext();

        // LinqDBDataContext ldc = new LinqDBDataContext(ConfigurationManager.ConnectionStrings["MyDataBaseConnectionString"].ConnectionString.ToString() );
        //----------------------------------------------------------------------------------------------

        //DataClassesDataContext dcdc = new DataClassesDataContext(
        //ConfigurationManager.ConnectionStrings["MyDataBaseConnectionString"].ConnectionString.ToString() );

        //var result = from r in dcdc.YuShouKuan
        //             where r.ID > 5
        //             select r;

        //GridView1.DataSource = result;
        //GridView1.DataBind();



    }

    //插入语句
    protected void Button1_Click( object sender , EventArgs e )
    {
        
        DataClassesDataContext dcdc = new DataClassesDataContext(
        ConfigurationManager.ConnectionStrings["MyDataBaseConnectionString"].ConnectionString.ToString() );
        YuShouKuan ysk = new YuShouKuan();
        ysk.所属公司 = TextBox1.Text;
        ysk.金额 =double.Parse( TextBox2.Text);
        ysk.收款人 = TextBox3.Text;
        //插入语句
        dcdc.YuShouKuan.InsertOnSubmit( ysk );
        //提交修改
        dcdc.SubmitChanges();
    }


    //修改语句
    protected void Button2_Click( object sender , EventArgs e )
    {
      
        DataClassesDataContext dcdc = new DataClassesDataContext(
        ConfigurationManager.ConnectionStrings["MyDataBaseConnectionString"].ConnectionString.ToString() );
        YuShouKuan ysk = new YuShouKuan();
        //这里的v类似临时表
        var result = from v in dcdc.YuShouKuan
                     where v.ID == 47
                     select v;
        foreach ( var item in result )
        {
            item.收款人 = "神海龙";
        }
        //提交修改
        dcdc.SubmitChanges();

    }


    //删除语句
    protected void Button3_Click( object sender , EventArgs e )
    {
        DataClassesDataContext dcdc = new DataClassesDataContext(
        ConfigurationManager.ConnectionStrings["MyDataBaseConnectionString"].ConnectionString.ToString() );
        //这里的v类似临时表
        var result = from v in dcdc.YuShouKuan
                     where v.ID ==  50
                     select v;
        //删除语句
        dcdc.YuShouKuan.DeleteOnSubmit((YuShouKuan)result );
       // dcdc.YuShouKuan.DeleteAllOnSubmit<YuShouKuan>(result );
        //提交修改
        dcdc.SubmitChanges();
    }
}