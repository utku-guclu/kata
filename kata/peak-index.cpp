#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr) {
  int lo = 0;
  int hi = arr.size() - 1;

  while (lo < hi) {
    int mid = (lo + hi) / 2;

    if (arr[mid] > arr[mid + 1]) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
    cout << mid << endl;
  }
  return hi;
};

int main() {
  vector<int> arr = {0, 2, 1, 0};
  cout << peakIndexInMountainArray(arr) << endl;
  return 0;
}
