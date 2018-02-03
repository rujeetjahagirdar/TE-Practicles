import java.sql.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import javax.swing.text.Document;

public class mysqlclient extends JFrame implements ActionListener{
 JTextField t1,t2;
 JButton b1,b2;
 void execute();
 mysqlclient(){
    setLayout(new FlowLayout());
    setSize(600,600);
 	t1=new JTextField(20);
    add(new JLabel("asdf"));
    t2=new JTextField(20);
    b1=new JButton("OK");
    b2=new JButton("Cancle");
    add(t1);
    add(t2);
    add(b1);
    add(b2);
    b1.addActionListener(this);
    b2.addActionListener(this);
    setVisible(true);
 }


public static void main(String arg[])throws Exception{
  Class.forName("com.mysql.jdbc.Driver");
  Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/dbtest?useSSL=false","root","toor");
  Statement st=con.createStatement();
  void execute() {
  	st.executeUpdate("create table rj(roll int, name varchar(10))");
  }
  new mysqlclient();
}

public void actionPerformed(ActionEvent e) {
 	if((e.getSource()).equals("OK")) {
 		execute();
 	}
 }

}
/* <applet code=mysqlclient height=600 width=600></applet>*/