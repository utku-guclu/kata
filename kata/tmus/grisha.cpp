#include <iostream>
using namespace std;

string grisha(int f) {
  constexpr int TOTAL_PROBLEMS = 12;
  constexpr int TOTAL_TIME = 300;      // 5 hours in minutes
  constexpr int FIRST_HOUR_TIME = 60;  // First hour in minutes
  constexpr int TIME_PER_PROBLEM = 45; // Time for each remaining problem

  int remaining_problems = TOTAL_PROBLEMS - f;
  int remaining_time = TOTAL_TIME - FIRST_HOUR_TIME;

  return (remaining_problems * TIME_PER_PROBLEM <= remaining_time) ? "YES"
                                                                   : "NO";
}

int main() {
  int f;
  cin >> f;
  cout << grisha(f) << endl;
  return 0;
}
