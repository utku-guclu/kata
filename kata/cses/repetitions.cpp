#include <bits/stdc++.h>
using namespace std;

int repetitions(string dna_sequence) {
  // find the longest repetition in the sequence
  int longest_repetition = 1;
  int current_repetition = 1;

  for (int i = 0; i < dna_sequence.length(); i++) {
    if (dna_sequence[i] == dna_sequence[i + 1]) {
      current_repetition++;
    } else {
      if (current_repetition > longest_repetition) {
        longest_repetition = current_repetition;
      }
      current_repetition = 1;
    }
  }

  return longest_repetition;
}

int main() {
  // get a dna sequence from user
  string dna_sequence;
  cin >> dna_sequence;
  // get the number of times to repeat
  cout << repetitions(dna_sequence) << "\n";

  return 0;
}
