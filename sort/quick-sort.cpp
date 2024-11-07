#include <iostream>
#include <vector>

// Function to partition the array around a pivot element
int partition(std::vector<int> &arr, int low, int high) {
  // Implement the partition logic here
  // Return the index of the pivot element
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

// Recursive quicksort function
void quickSort(std::vector<int> &arr, int low, int high) {
  if (low < high) {
    // Find the pivot index
    int pivotIndex = partition(arr, low, high);

    // Recursively sort the left and right partitions
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  }
}

int main() {
  std::vector<int> arr = {5, 2, 8, 1, 9, 3};

  // Sort the array using quicksort
  quickSort(arr, 0, arr.size() - 1);

  // Print the sorted array
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
