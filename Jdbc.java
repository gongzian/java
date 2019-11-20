import java.sql.*;

public class Jdbc {

    public static final String URL = "jdbc:mysql://localhost:3306/runoob?useSSL=false&serverTimezone=UTC";
    public static final String USER = "root";
    public static final String PASSWORD = "Gza19981016";

    public static void main(String[] args) throws Exception {

        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery("SELECT firstname, lastname, city, state from person a, address b where a.personid=b.personid");

        System.out.println("+-------------+-------------+------------------+----------+");
        System.out.println("|  FirstName  |   LastName  |   City           |  State   |");
        System.out.println("+-------------+-------------+------------------+----------+");

        while(rs.next()){
            System.out.printf("%-14s", "|  " +rs.getString("firstname"));
            System.out.printf("%-14s", "|   " + rs.getString("lastname"));
            System.out.printf("%-19s", "|   " +rs.getString("city"));
            System.out.printf("%-11s", "|  " +rs.getString("state"));
            System.out.println("|");
        }
        System.out.println("+-------------+-------------+------------------+----------+");
    }
}
