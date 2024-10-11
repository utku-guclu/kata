import java.util.Scanner;

public class YourLuck {

  public static void main(String[] args) {
    Scanner printer = new Scanner(System.in);

    System.out.println("Hello, what is your name?");

    String name = printer.next();

    System.out.println("Hi, " + name + "!");

    System.out.println("How old are you?");

    int age = printer.nextInt();

    int length = name.length();

    int luck = 0;

    if (age < 15) {
      luck = (length * age) % 10;
    } else if (age < 20) {
      luck = (age * age - length) % 10;
    } else if (age < 30) {
      luck = (length - age) % 10;
    } else if (age < 40) {
      luck = (age + length) % 10;
    } else {
      luck = (age / length) % 10;
    }

    if (luck < 0)
      luck = luck * -1;

    System.out.println("Your luck number is " + luck);
  }

}
