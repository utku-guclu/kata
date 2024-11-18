#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int min_squares(int N) {
  // dp[i] will store the minimum number of squares needed to sum up to i
  vector<int> dp(N + 1, N + 1); // Initialize with a large value (N + 1)
  dp[0] = 0;                    // Base case: 0 quadrics need 0 squares

  // Fill the dp array
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j * j <= i; j++) {
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }

  // The answer will be the minimum number of squares for N quadrics
  return dp[N];
}

int main() {
  int N;
  cin >> N; // Input the number of quadrics

  cout << min_squares(N) << "\n"; // Output the minimum number of certificates
  return 0;
}
