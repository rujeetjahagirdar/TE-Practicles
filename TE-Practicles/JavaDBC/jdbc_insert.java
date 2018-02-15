/*Rujeet Jahagirdar
Roll 32
TE-CSE 1
insert query*/
import java.sql.*;

public class jdbc_insert {
	public static void main(String arg[]) throws Exception {
		Class.forName("com.mysql.jdbc.Driver");
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/rjtest?useSSL=false","root","toor");
		Statement st=con.createStatement();
		st.executeUpdate("insert into rjtable values(3,'mahesh')");
		System.out.println("Inserted");
		st.close();
        Statement st1=con.createStatement();
        ResultSet rs=st1.executeQuery("select * from rjtable");
		while(rs.next()) {
			System.out.println(rs.getInt(1)+"\t"+rs.getString(2));
		}
		con.close();
	}
}

/*OUTPUT
Inserted
1	rujeet
2	umesh
3	mahesh

*/
