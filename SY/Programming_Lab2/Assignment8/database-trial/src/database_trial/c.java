package database_trial;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class c {
	static final String DB_URL = "jdbc:mysql://localhost:3306/programming_lab_2";
	static final String USERNAME = "root";
	static final String PASSWORD = "Jay@1234";
	public static void main(String args[]) {
		Connection conn = null;
		Statement stmt = null;
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			
			System.out.println("Connecting to database ...");
			
			conn = DriverManager.getConnection(DB_URL, USERNAME, PASSWORD);
			
			System.out.println("Successfully connected!");
			
			stmt = conn.createStatement();
			
			System.out.println("Updating Sangli to Pune...");
			
			String sql = "UPDATE Student SET City='Pune' WHERE City='Sangli'";
			stmt.executeUpdate(sql);
			System.out.println("Done updating!");
			
		}
		catch(Exception e) {
			System.out.println(e);
		}
	}
}
