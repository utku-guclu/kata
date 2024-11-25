#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
private:
  int backtrack(unordered_map<char, int> &freq) {
    int count = 0;

    for (auto &[char_, freq_count] : freq) {
      if (freq_count > 0) {
        // pre
        count++;

        freq_count--;

        count += backtrack(freq);
        // post
        freq_count++;
      }
    }
    return count;
  }

public:
  int numTilePossibilities(string tiles) {
    unordered_map<char, int> freq;
    for (char c : tiles) {
      freq[c]++;
    }
    // Print the frequency map
    // for (auto &[char_, freq_count] : freq) {
    //   cout << char_ << ": " << freq_count << endl;
    // }
    return backtrack(freq);
  }
};

int main() {
  Solution s;
  std::cout << s.numTilePossibilities("AAB") << endl;

  return 0;
}
