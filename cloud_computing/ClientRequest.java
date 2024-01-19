import java.rmi.*;
public class ClientRequest
{
    public static void main(String args[])
    {
        String answer,value="Cloud";
        try
        {
            // lookup method to find reference of remote object
            Search access =
                (Search)Naming.lookup("rmi://192.168.72.86:1900"+
                                      "/cloudcomp");
            answer = access.query(value);
            System.out.println("Response: " + answer);
        }
        catch(Exception ae)
        {
            System.out.println(ae);
        }
    }
}
