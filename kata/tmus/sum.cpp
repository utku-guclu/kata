/* Your task is to find the sum of all integer numbers lying between 1 and N
inclusive. Input The input consists of a single integer N that is not greater
than 10000 by it's absolute value. Output Write a single integer number that is
the sum of all integer numbers lying between 1 and N inclusive. Sample input
output

-3

-5 */

#include <iostream>

int main() {
  int n;
  std::cin >> n;

  // Check if n is within the allowed range and not zero
  if (n > 10000 || n < -10000) {
    /*     std::cout << "0\n"; */
    return 1;
  }

  if (n == 0) {
    std::cout << "1\n";
    return 0;
  }

  long long sum = 0;

  if (n > 0) {
    // Positive case: sum from 1 to n
    sum = (long long)n * (n + 1) / 2;
  } else if (n < 0) {
    // Negative case: sum from n to 1
    sum = ((long long)(2 - n) * (n + 1)) /
          2; // Alternatively, sum = (2 - n)(n + 1)/2
  }
  // sum remains 0 when n == 0, as no action is taken

  std::cout << sum << "\n";
  return 0;
}
