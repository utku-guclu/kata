public class Arrays {

  public static void main(String[] args) {
    // int[] numbers = { 1, 2, 3, 4, 5 };
    int[] numbers = new int[10];
    numbers[6] = 6;
    sum(numbers);

    // int[][] twoDimensionalNumbers = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    int[][] twoDimensionalNumbers = new int[3][10];
    twoDimensionalNumbers[0][9] = 6;
    twoDimensionalNumbers[1][6] = 6;
    twoDimensionalNumbers[2][3] = 6;

    int twoSum = twoDimensionalSum(twoDimensionalNumbers);

    System.out.println(twoSum);
  }

  public static int sum(int[] numbers) {
    int sum = 0;
    for (int i = 0; i < numbers.length; i++) {
      // System.out.println(numbers[i] == 0 ? "X" : numbers[i]);
      sum += numbers[i];
    }
    return sum;
  }

  public static int twoDimensionalSum(int[][] numbers) {
    int sum = 0;
    for (int i = 0; i < numbers.length; i++) {
      for (int j = 0; j < numbers[i].length; j++) {
        // System.out.println(numbers[i][j] == 0 ? "X" : numbers[i][j]);
        System.out.print(numbers[i][j]);
        sum += numbers[i][j];
      }
      System.out.println();
    }
    return sum;
  }

}
