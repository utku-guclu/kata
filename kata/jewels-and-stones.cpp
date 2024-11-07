#include <iostream>
#include <string>
#include <unordered_set>

int numJewelsInStones(std::string jewels, std::string stones) {
  std::unordered_set<char> jewelsSet;
  for (char c : jewels) {
    jewelsSet.insert(c);
  }

  int count = 0;
  for (char c : stones) {
    if (jewelsSet.find(c) != jewelsSet.end()) {
      count++;
    }
  }

  return count;
}

int main() {
  std::string jewels = "aA";
  std::string stones = "aAAbbbb";
  int result = numJewelsInStones(jewels, stones);
  std::cout << result << std::endl;
  return 0;
}
