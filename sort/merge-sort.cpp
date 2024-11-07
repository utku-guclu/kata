#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int low, int mid, int high) {
  std::vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
  std::vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);

  int i = 0, j = 0, k = low;

  while (i < left.size() && j < right.size()) {
    if (left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }
  // remaining elements
  while (i < left.size()) {
    arr[k++] = left[i++];
  }
  while (j < right.size()) {
    arr[k++] = right[j++];
  }
}

void mergeSort(std::vector<int> &arr, int low, int high) {
  // We'll implement the logic here
  if (low < high) // base case;
  {
    // We have more than one element, so we need to sort the partition
    int mid = (low + high) / 2;
    // Recursively sort the left and right partitions.
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // Merge the sorted partitions
    merge(arr, low, mid, high);
  }
}

int main() {
  std::vector<int> arr = {5, 2, 8, 1, 9, 3};

  // Sort the array using mergesort
  mergeSort(arr, 0, arr.size() - 1);

  // Print the sorted array
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
