import java.io.*;
import java.util.*;

public class Ex {

  public static void main(String[] args) {
    HashMap<String, String> map = new HashMap<String, String>();
    Scanner in = new Scanner(System.in);

    int n = 0;

    // Handle invalid input for number of entries
    try {
      System.out.println("Enter the number of entries:");
      n = Integer.parseInt(in.nextLine()); // Read the input as a string, then convert to integer
    } catch (NumberFormatException e) {
      System.err.println("Error: Number of entries must be a valid integer.");
      return; // Exit if the input is not valid
    }

    // Reading the input entries and storing them in the map
    for (int i = 0; i < n; i++) {
      String name = in.nextLine(); // Read the name

      // Handle invalid phone number input with a try-catch block
      try {
        String phone = in.nextLine(); // Read the phone number as a string
        if (!phone.matches("\\d+")) { // Check if the phone number contains only digits
          throw new NumberFormatException(); // Manually throw exception if not valid
        }
        map.put(name, phone);
      } catch (NumberFormatException e) {
        System.err.println("Error: Phone number must contain only digits. Invalid input for " + name);
        return; // Stop execution when an invalid input is encountered
      }
    }

    // Handling queries until input ends
    while (in.hasNext()) {
      String query = in.nextLine();

      // Search in the map for the queried name
      String phone = map.get(query);

      // Output the result
      if (phone == null) {
        System.out.println("Not found");
      } else {
        System.out.println(query + "=" + phone);
      }
    }

    in.close();
  }
}

