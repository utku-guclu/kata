
// write a function whether the number is Armstrong number or not
// An Armstrong number (or narcissistic number) is a number that is equal to the sum of its digits each raised to the power of the number of digits. For example, 153 is an Armstrong number because:

// grab the number from the argument
// convert the number to string
// split the string
// convert the string to int
// use for loop
// add the number to the sum
// return the sum

public class Armstrong {
  public static void main(String[] args) {
    int num = 153; // 1 + 125 + 27 = 153
    System.out.println(isArmstrong(num));
  }

  public static boolean isArmstrong(int num) {
    String number = Integer.toString(num);
    int sum = 0;
    for (int i = 0; i < number.length(); i++) {
      sum += Math.pow(Integer.parseInt(number.substring(i, i + 1)), number.length());
    }
    return sum == num;
  }
}

// to compile: javac Armstrong.java
// to run: java Armstrong
