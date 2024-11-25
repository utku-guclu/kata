#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {

public:
  int shortestWordDistance(std::vector<std::string> &words, std::string source,
                           std::string target) {
    // if source and target are the same return 0
    if (source == target)
      return 0;

    // Convert words to a set for faster lookup
    std::unordered_set<std::string> wordSet(words.begin(), words.end());

    // If target is not in the set, return -1
    if (wordSet.find(target) == wordSet.end())
      return -1;

    // Queue for BFS
    std::queue<std::string> queue;

    // Visited set to avoid visiting the same word twice
    std::unordered_set<std::string> visited;

    // Start BFS from source
    queue.push(source);
    visited.insert(source);

    // Track the number of transformations
    int transformations = 0;

    while (!queue.empty()) {
      int size = queue.size();

      // Process all words at the current transformation level
      for (int i = 0; i < size; i++) {
        std::string currentWord = queue.front();
        queue.pop();

        // If we found the target, return the number of transformations
        if (currentWord == target)
          return transformations;

        // Try changing each character
        for (int j = 0; j < currentWord.length(); j++) {
          std::string temp = currentWord;

          // Try replacing each character with a lowercase letter
          for (char c = 'a'; c <= 'z'; c++) {
            temp[j] = c;
            // If the resulting word is in the set and not visited, add it to
            // the queue
            if (wordSet.find(temp) != wordSet.end() &&
                visited.find(temp) == visited.end()) {
              queue.push(temp);
              visited.insert(temp);
            }
          }
        }
      }
      // Move to the next transformation level
      transformations++;
    }
    // If we haven't found the target, return -1
    return -1;
  }
};

int main() {
  Solution solution;
  std::vector<std::string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
  std::string source = "hit";
  std::string target = "cog";
  int shortestDistance = solution.shortestWordDistance(words, source, target);
  std::cout << "Shortest distance: " << shortestDistance << "\n";
  return 0;
}
