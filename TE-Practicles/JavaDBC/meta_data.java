/*Rujeet Jahagirdar
Roll No 32
TE-CSE 1
meta_data
*/
import java.sql.*;

public class meta_data {
	public static void main(String arg[]) throws Exception {
		Class.forName("com.mysql.jdbc.Driver");
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/rjtest?useSSL=false","root","toor");
		PreparedStatement pst=con.prepareStatement("select * from rjtable");
		ResultSet rs=pst.executeQuery();
		ResultSetMetaData rsmd=rs.getMetaData();
		System.out.println("Total columns= "+rsmd.getColumnCount());
		for (int i=0;i<rsmd.getColumnCount();i++) {
			System.out.println("Column Name: "+rsmd.getColumnName(i+1)+"\t"+"Column Type: "+rsmd.getColumnTypeName(i+1));
		}
		con.close();
	}
}

/*
OUTPUT
Total columns= 2
Column Name: roll	Column Type: INT
Column Name: name	Column Type: VARCHAR

*/