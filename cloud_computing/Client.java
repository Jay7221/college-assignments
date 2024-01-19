import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
    public static void main(String[] args) {
        try {
            Registry registry = LocateRegistry.getRegistry("10.40.4.83", 9000);
            
            Product laptop = (Product) registry.lookup("laptop");
            String laptopName = laptop.getName();
            String laptopDescription = laptop.getDescription();
            double price = laptop.getPrice();


            System.out.println("Name: " + laptopName);
            System.out.println("Description: " + laptopDescription);
            System.out.println("Price: " + price);
        } catch (Exception e) {
            System.out.println("Exception in client side: " + e);
        }
    }
}
