package database_trial;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class d {
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
			
			System.out.println("Fetching data...");
			
			String sql = "SELECT * FROM Student WHERE Marks > 60";
			ResultSet res = stmt.executeQuery(sql);
			
			System.out.println("Done fetching data!");

			System.out.println("Students with marks greater than 60 are : ...");
			
			System.out.println(res);
			while(res.next()) {
				int Roll_No = res.getInt("Roll_No");
				String Name = res.getString("Name");
				int Marks = res.getInt("Marks");
				System.out.println("Roll No : " + Roll_No + ",\t Name : " + Name + ",\t Marks : " + Marks);
			}
		}
		catch(Exception e) {
			System.out.println(e);
		}
	}
}