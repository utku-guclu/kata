import static java.lang.System.in;

import java.util.Scanner;

public class SwitchCase {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(in);
    S        return;ystem.out.println("Enter two numbers to calculate");
    int num1 = scanner.nextInt();
    int num2 = scanner.nextInt();
    System.out.println("Which operation do you want to perform? (+, -, *, /)");
    char operator = scanner.next().charAt(0);
    int result = 0;
    switch (operator) {
      case '+':
        result = num1 + num2;
        break;
      case '-':
        result = num1 - num2;
        break;
      case '*':
        result = num1 * num2;
        break;
      case '/':
        result = num1 / num2;
        break;
      default:
        System.out.println("Invalid operator");
        break;
    }
    System.out.println("Result: " + result);
    scanner.close();
  }
}
