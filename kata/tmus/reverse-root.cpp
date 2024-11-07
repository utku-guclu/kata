/* The problem is so easy, that the authors were lazy to write a statement for
it! Input The input stream contains a set of integer numbers Ai (0 ≤ Ai ≤ 1018).
The numbers are separated by any number of spaces and line breaks. A size of the
input stream does not exceed 256 KB. Output For each number Ai from the last one
till the first one you should output its square root. Each square root should be
printed in a separate line with at least four digits after decimal point. Sample
input	output

 1427  0

   876652098643267843
5276538





2297.0716
936297014.1164
0.0000
37.7757
*/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  // Read the entire input into a string
  std::string input;
  std::getline(std::cin, input, '\0'); // Read until end of input (EOF)

  // Use a stringstream to parse integers from the input string
  std::stringstream ss(input);
  std::vector<long long> numbers; // To store the numbers
  long long num;

  // Parse each number from the input and store it in the vector
  while (ss >> num) {
    numbers.push_back(num);
  }

  // Set the output format to fixed and precision to 4 decimal places
  std::cout << std::fixed << std::setprecision(4);

  // Output each square root in reverse order
  for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
    double squareRoot = std::sqrt(*it);
    std::cout << squareRoot << "\n"; // Print the square root
  }

  return 0;
}
