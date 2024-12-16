#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
      // Count odd-length palindromes (centered at one character)
      count += expandFromCenter(s, i, i);
      // Count even-length palindromes (centered between two characters)
      count += expandFromCenter(s, i, i + 1);
    }
    return count;
  }

private:
  int expandFromCenter(const string &s, int left, int right) {
    int count = 0;
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      cout << "left" << left << "right" << right << "\n";
      count++;
      left--;
      right++;
    }
    return count;
  }
};
int main() {
  Solution s;
  cout << s.countSubstrings("abc");
  return 0;
}
