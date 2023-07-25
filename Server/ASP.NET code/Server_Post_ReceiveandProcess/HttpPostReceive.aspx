<%@ Page Language="C#" AutoEventWireup="true" CodeFile="HttpPostReceive.aspx.cs" Inherits="HttpPostReceive" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>接收POST資料的後端 並進行處理</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
        	<asp:AccessDataSource ID="AccessDataSource1" runat="server" DataFile="/Test/Post/App_Data/EnvPar.mdb" SelectCommand=""></asp:AccessDataSource>
        </div>
    </form>
</body>
</html>
