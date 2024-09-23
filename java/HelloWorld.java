public class HelloWorld {
  public static void main(String[] args) {
    String s = "Hello,";

    char firstLetter = s.charAt(0);

    System.out.println(s + " World!");
    // print out the first letter
    System.out.println(firstLetter);
    // examples of number types
    int i = 0;
    long l = 0;
    float f = 0.0f;
    double d = 0.0;
    System.out.println("i = " + i + ", l = " + l + ", f = " + f + ", d = " + d);
  }
}

// to run the code:
// javac HelloWorld.java
// java HelloWorld
