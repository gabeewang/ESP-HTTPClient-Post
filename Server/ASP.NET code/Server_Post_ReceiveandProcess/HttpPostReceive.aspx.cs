using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class HttpPostReceive : System.Web.UI.Page
{
	protected void Page_Load(object sender, EventArgs e)
	{
		String Temp = Request.Form["Temp"].ToString();

		if (Temp != "")
		{
			AccessDataSource1.InsertCommand = String.Format("INSERT INTO [Temp] (Parameter) VALUES ({0})", Temp); //定義新增資料的SQL
			AccessDataSource1.Insert(); //將資料寫入資料庫

			Title = "OK";
		}
		else
		{
			Title = "Post Error";
		}
	}
}