/*Rujeet Jahagirdar
ROll 32
TE-CSE 1
select query*/
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.*;

public class jdbc_select {
	public static void main(String args[]) throws Exception {
		Class.forName("com.mysql.jdbc.Driver");
		Connection con= DriverManager.getConnection("jdbc:mysql://localhost:3306/rjtest?useSSL=false","root","toor");
		Statement st= con.createStatement();
		ResultSet rs=st.executeQuery("select * from rjtable");
		while(rs.next()) {
			System.out.println(rs.getInt(1)+"\t"+rs.getString(2));
		}
	}
}

/*OUTPUT
1	rujeet
2	umesh
3	mahesh
*/
