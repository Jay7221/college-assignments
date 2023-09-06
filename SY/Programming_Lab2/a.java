import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
public class a {
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
			String sql = "";
			stmt = conn.createStatement();
			
			
			System.out.println("Creating table Student...");
			sql = "CREATE TABLE Student(Roll_No int,Name varchar(30),City varchar(30),Grade char(3),Marks float)";
			System.out.println("Done creating table!");
			
			stmt.executeUpdate(sql);
			System.out.println("Inserting data into table...");
			sql = "INSERT INTO Student (Roll_No, Name, City, Grade, Marks) " +
                    "VALUES (1, 'Atul', 'Sangli', 'A', 90.50), " +
                    "(2, 'Sangram', 'Sangli', 'B', 70.25), " +
                    "(3, 'Satya', 'Mumbai', 'B', 61.36), " +
                    "(4, 'Jaydeep', 'Pune', 'B', 60.95), " +
                    "(5, 'Prashant', 'Sangli', 'C', 55.26), " +
                    "(6, 'Abhi', 'Pune', 'C', 55.84)";
			
			stmt.executeUpdate(sql);
			System.out.println("Done inserting data into table!");
		}
		catch(Exception e) {
			System.out.println(e);
		}
	}
}
