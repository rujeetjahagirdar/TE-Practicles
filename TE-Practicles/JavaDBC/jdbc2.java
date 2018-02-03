import java.sql.*;

class jdbc2 {
	public static void main(String arg[]) throws Exception {
		Class.forName("com.mysql.jdbc.Driver");
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/rjtest","root","toor");
		Statement st=con.createStatement();
		st.executeUpdate("create table table1 (roll int,name varchar(10))");
		System.out.println("Table created");
		st.close();
		con.close();
	}
}