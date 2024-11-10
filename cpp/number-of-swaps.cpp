#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int minSwapsToConvertArray(vector<int> &arr1, vector<int> &arr2) {
  int n = arr1.size();
  unordered_map<int, int> targetPos;
  for (int i = 0; i < n; i++) {
    targetPos[arr2[i]] = i;
  }

  vector<bool> visited(n, false);
  int swapCount = 0;

  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      continue;
    }
    int cycleSize = 0;
    int j = i;
    while (!visited[j]) {
      visited[j] = true;
      j = targetPos[arr1[j]];
      cycleSize++;
    }
    if (cycleSize > 1) {
      swapCount += cycleSize - 1;
    }
  }

  return swapCount;
}

int main() {
  vector<int> arr1 = {7, 6, 1, 3, 4, 9, 8, 2, 5};
  vector<int> arr2 = {3, 1, 8, 5, 4, 9, 2, 6, 7};
  cout << minSwapsToConvertArray(arr1, arr2) << endl;
  return 0;
}
