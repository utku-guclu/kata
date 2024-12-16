
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr) {
  int n = arr.size() + 1;
  int sum = (n * (n + 1)) / 2;
  int actual_sum = accumulate(arr.begin(), arr.end(), 0);
  return sum - actual_sum;
}

int main() {
  // The first input line contains an integer n.
  // The second line contains n−1 integers t1,t2,...,tn−1.
  int n;
  cin >> n;

  if (n < 2)
    return 1;

  vector<int> arr(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> arr[i];
  }

  cout << missingNumber(arr) << endl;
  return 0;
}
