// A letter can be encoded to a number in the following way:
//
// 'A' -> '1', 'B' -> '2', 'C' -> '3', ..., 'Z' -> '26'
//
// A message is a string of uppercase letters, and it is encoded first using
// this scheme. For example, 'AZB' -> '1262'
//
// Given a string of digits S from 0-9 representing an encoded message, return
// the number of ways to decode it.
//
// Examples:
//
// input:  S = '1262'
// output: 3
// explanation: There are 3 messages that encode to '1262': 'AZB', 'AB

#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
  int decodeVariations(string S) {
    // Memo
    vector<int> memo(S.length(), -1);   // initialize with -1
    return recursiveDecode(S, 0, memo); // start from index 0
  }

private:
  /**
   * @param S: A string of digits
   * @param index: An integer
   * @param memo: An array of integers
   * @return: An integer
   */

  int recursiveDecode(const string &S, int index, vector<int> &memo) {
    // Base cases
    if (index == S.length())
      return 1; // end of string
    if (S[index] == '0')
      return 0; // invalid

    // Check memoized result
    if (memo[index] != -1)
      return memo[index]; // memo

    // Recursive case 1: Single digit decoding
    int ways = recursiveDecode(S, index + 1, memo);

    // Recursive case 2: Two digit decoding
    if (index + 1 < S.length()) {
      int twoDigit = stoi(S.substr(index, 2));
      if (twoDigit <= 26 && twoDigit >= 10) {
        ways += recursiveDecode(S, index + 2, memo);
      }
    }

    // memoize and return
    return memo[index] = ways;
  }
};

int main() {
  Solution sol;
  string S = "1262";
  cout << sol.decodeVariations(S) << endl;
  return 0;
}
