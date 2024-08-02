#include <iostream>

unsigned int countBits(unsigned long long n){
  /* 
    Bitwise AND Operation: (n & 1) checks if the least significant bit is 1. If it is, it adds 1 to the count.
    Right Shift Operation: n >>= 1 shifts all bits of n to the right by one position, effectively dividing n by 2 and discarding the least significant bit.
    Loop Condition: The loop continues while n is greater than 0.
 **/
  int count {};
  while (n > 0) 
  {
    // Increment count if the least significant bit is 1
    count += (n & 1);
    // Right shift the number by 1 bit
    n >>= 1;
    std::cout << "count: " << count << "\n";
    std::cout << "n: " << n << "\n";
  }
  return count;
}

int main()
{
    unsigned long long n;
    std::cin >> n;
    std::cout << countBits(n) << "\n";
    return 0;
}
