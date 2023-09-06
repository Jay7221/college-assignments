import java.io.*;
import java.sql.*;

public class main{
	public static void main(String args[]) {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/tree", "root", "Jay1234");
		}
		catch(Exception e) {
			System.out.println(e);
		}
	}
}

