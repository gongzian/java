import java.sql.*;

public class Jdbc {

    public static final String URL = "jdbc:mysql://localhost:3306/runoob?useSSL=false&serverTimezone=UTC";
    public static final String USER = "root";
    public static final String PASSWORD = "Gza19981016";

    public static void main(String[] args) throws Exception {

        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
        Statement stmt = conn.createStatement();

        ABCD abcd = new ABCD();
        abcd.AddSelect("firstname");
        abcd.AddSelect("lastname");
        abcd.AddSelect("city");
        abcd.AddSelect("state");

        abcd.AddFrom("person a");
        abcd.AddFrom("person b");

        abcd.AddWhere("a.personid=b.personid");

        //System.out.println(abcd.GetSQL());

        ResultSet rs = stmt.executeQuery(abcd.GetSQL());
        //ResultSet rs = stmt.executeQuery("SELECT firstname, lastname, city, state from person a, address b where a.personid=b.personid");

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

class ABCD{

    String select="SELECT ";
    String from = " FROM ";
    String where=" WHERE ";

    void AddSelect(String s){
        if(select.length()==7){
            select +=s;
        }else{
            select = select + ", " + s;
        }
    }

    void AddFrom(String s){
        if(from.length()==6){
            from +=s;
        }else{
            from = from + ", " + s;
        }
    }

    void AddWhere(String s){
        if(where.length()==7){
            where +=s;
        }else{
            where = where + ", " + s;
        }
    }

    String GetSQL(){
        return select+from+where;
    }
}
