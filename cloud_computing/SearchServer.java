import java.rmi.*;
import java.rmi.registry.*;
public class SearchServer
{
    public static void main(String args[]){
        try{
            Search obj = new SearchQuery();

            LocateRegistry.createRegistry(1900);
            Naming.rebind("rmi://127.0.0.1:1900" + "/cloudcomp", obj);
        }
        catch(Exception ae){
            System.out.println(ae);
        }
    }
}