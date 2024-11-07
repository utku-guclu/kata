#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

/*
std::vector<int> find_largest(const std::vector<int> &input, int m) {
  if (input.empty() || m <= 0 || m > input.size()) {
    return {};
  }

  std::vector<int> largest_nums;
  std::vector<bool> used(input.size(), false);

  while (largest_nums.size() < m) {
    int maxIndex = -1;
    int maxNumber = INT_MIN;

    // Find the largest unused number
    for (int i = 0; i < input.size(); ++i) {
      if (!used[i] && input[i] > maxNumber) {
        maxNumber = input[i];
        maxIndex = i;
      }
    }

    // Mark the found number as used
    if (maxIndex != -1) {
      used[maxIndex] = true;
      largest_nums.push_back(maxNumber);
    }
  }
  // Sort the largest numbers in ascending order
  std::sort(largest_nums.begin(), largest_nums.end());

  return largest_nums;
}
*/

#include <functional>
#include <queue>

std::vector<int> find_largest(const std::vector<int> &input, int m) {
  if (input.empty() || m <= 0) {
    return {};
  }

  // Using a min-heap to store the m largest elements
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

  for (int num : input) {
    if (min_heap.size() < m) {
      min_heap.push(num);
    } else if (num > min_heap.top()) {
      min_heap.pop();
      min_heap.push(num);
    }
  }

  // Transfer elements from the heap to a vector
  std::vector<int> largest_elements;
  while (!min_heap.empty()) {
    largest_elements.push_back(min_heap.top());
    min_heap.pop();
  }

  return largest_elements;
}

// comment out main() before running tests
int main() {
  // debug your code below
  std::vector<int> input = {1, 5, 4, 2, 3};
  int m = 3;
  std::vector<int> result = find_largest(input, m);
  for (int num : result) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  return 0;
}
