/* Start: (0,0) - top left
Destination: (4,4) - bottom right
Now it's clear:

Upper left triangle (including diagonal) is blocked (🟦)
Lower right triangle is open (⬜)
You can move only right (→) or up (↑)
Need to find number of possible paths from (0,0) to (4,4) */

#include <iostream>

class Solution {
public:
  int countPaths(int n) { return dfs(n - 1, 0, n); }

private:
  bool isValid(int row, int col, int n) {
    return (row >= 0 && row < n && col >= n - 1 - row && col < n);
  }

  int dfs(int row, int col, int n) {
    if (!isValid(row, col, n))
      return 0;
    if (row == 0 && col == n - 1)
      return 1;
    return dfs(row - 1, col, n) + dfs(row, col + 1, n);
  }
};

int main() {
  Solution s;
  std::cout << s.countPaths(4) << std::endl;
  return 0;
}
