#include <bits/stdc++.h>
using namespace std;

void repetitions(string dna_sequence) {
  // find the longest repetition in the sequence
  int longest_repetition = 0;
  int current_repetition = 0;

  for (int i = 0; i < dna_sequence.length(); i++) {
    if (dna_sequence[i] == dna_sequence[i + 1]) {
      current_repetition++;
    } else {
      if (current_repetition > longest_repetition) {
        longest_repetition = current_repetition;
      }
      current_repetition = 0;
    }
  }
}
int main() {
  // get a dna sequence from user
  string dna_sequence;
  cin >> dna_sequence;
  // get the number of times to repeat
  repetitions(dna_sequence);

  return 0;
}
