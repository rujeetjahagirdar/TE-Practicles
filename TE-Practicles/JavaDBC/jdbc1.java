import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.*;

public class jdbc1 {
	public static void main(String args[]) throws Exception {
		Class.forName("com.mysql.jdbc.Driver");
		Connection con= DriverManager.getConnection("jdbc:mysql://localhost:3306/rjtest?useSSL=false","root","toor");
		Statement st= con.createStatement();
		ResultSet rs=st.executeQuery("select * from rjtable");
		while(rs.next()) {
			System.out.println(rs.getInt(1)+"\t"+rs.getString(2));
		}
		/*st.executeUpdate("insert into rjtable values(6,'nisha')");
		System.out.println("Inserted");
		ResultSet rst=st.executeQuery("select * from rjtable");
		while(rst.next()) {
			System.out.println(rst.getInt(1)+"\t"+rst.getString(2));
		}*/
	}
}