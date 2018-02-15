/*Rujeet Jahagirdar
Roll No 32
TE-CSE 1
prepared_select
*/
import java.sql.*;

public class prepared_select {
	public static void main(String arg[]) throws Exception {
		Class.forName("com.mysql.jdbc.Driver");
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/rjtest?useSSL=false","root","toor");
		PreparedStatement pst=con.prepareStatement("select * from rjtable");
		ResultSet rs=pst.executeQuery();
		while(rs.next()) {
			System.out.println(rs.getInt("roll")+"\t"+rs.getString("name"));
		}
		pst.close();
		con.close();
	}
}

/*OUTPUT
1	rujeet
2	umesh
3	mahesh

*/