public class BigO {
  public static void main(String[] args) {
    int n = 100000;

    // O(n)
    for (int i = 0; i < n; i++) {
      System.out.println(i);
    }

    // O(n^2)
    // O(n)
    for (int i = 0; i < n; i++) {
      // O(n)
      for (int j = 0; j < n; j++) {
        // O(1)
        System.out.println(i + j);
      }
    }

  }
}
