#include <algorithm> // for sorting the result
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> largest_numbers(const std::vector<int> &array, int target) {
  // Min heap to track the `target` largest numbers
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

  for (int num : array) {
    // Push the current number into the heap
    min_heap.push(num);

    // If the heap exceeds the target size, remove the smallest element
    if (min_heap.size() > target) {
      min_heap.pop();
    }
  }

  std::vector<int> result; // Declare a vector to store the result.

  while (!min_heap.empty()) {         // Loop until the heap is empty.
    result.push_back(min_heap.top()); // Add the smallest element (top of the
                                      // heap) to the result vector.
    min_heap.pop(); // Remove the smallest element from the heap.
  }

  // Sort the result in descending order (optional)
  std::sort(result.rbegin(), result.rend());

  return result;
}

int main() {
  std::vector<int> array = {3, 5, 7, 9};
  int target = 2;

  std::vector<int> result = largest_numbers(array, target);

  std::cout << "Largest " << target << " numbers: ";
  for (int num : result) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  return 0;
}

/* Heap Operations:

    Inserting into the heap: O(nlog⁡k)O(nlogk), where nn is the number of
elements and kk is target.

Sorting the Result (optional):

    O(klog⁡k)O(klogk).

Overall Complexity: O(nlog⁡k+klog⁡k)O(nlogk+klogk). */

/* #include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> largestNums(const std::vector<int> &nums, int target) {
  // Copy the original vector to avoid modifying it
  std::vector<int> sortedNums = nums;

  // Sort the numbers in descending order
  std::sort(sortedNums.begin(), sortedNums.end(), std::greater<int>());

  // Select the first `target` elements
  std::vector<int> result(
      sortedNums.begin(),
      sortedNums.begin() +
          std::min(target, static_cast<int>(sortedNums.size())));

  return result;
}

int main() {
  std::vector<int> nums = {2, 3, 4, 5, 2};
  int target = 3;

  std::vector<int> result = largestNums(nums, target);

  // Output the result
  std::cout << "Largest " << target << " numbers are: ";
  for (int num : result) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
} */
