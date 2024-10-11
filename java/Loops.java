public class Loops {

  public static void main(String[] args) {

    for (int i = 0; i < 5; i++) {
      for (int j = 5; j > i; j--) {
        System.out.print("*");
      }
      System.out.println();
    }

    /*
     * for (int i = 0; i < 10; i++) {
     * System.out.println(i);
     * }
     * 
     * int i = 0;
     * while (i < 10) {
     * System.out.println(i);
     * i += 5;
     * }
     * 
     * do {
     * System.out.println("Hello, World!");
     * } while (i < 10);
     */
  }
}
