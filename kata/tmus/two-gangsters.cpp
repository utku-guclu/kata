#include <iostream>

using namespace std;

/* Two gangsters Harry and Larry had a rest at countryside. They decided to
spend some time shooting, so they put several beer cans (no more than 10) on a
log. Harry started to shoot cans one after another from the leftmost to the
right and Larry – from the rightmost to the left. At some moment it happened so
that they shot one and the same can. Harry got indignant and claimed that Larry
owed him a considerable sum of money because Larry deprived him of shooting some
more cans. Larry became furious and told Harry that he owed even greater sum of
money to Larry because of the same reason. They started to argufy but nobody
remembered how many cans there were at the very beginning. And no one of them
was going to search cans which was shot. Anyway, each of them remembered exactly
how many cans he shot. Determine how many cans were not shot by Harry and how
many cans were not shot by Larry. Input The only input line contains two
integers — the number of cans shot by Harry and by Larry respectively. Output
two integers — the number of cans that were not shot by Harry and the number of
cans that were not shot by Larry, respectively.

Sample input
4 7

output
6 3 */

pair<int, int> solveCanShooting(int harryShoots, int larryShoots) {
  // Step 1: Calculate total number of cans
  // When we add harryShots + larryShots, we're counting the overlapped can
  // twice So we subtract 1 to get the actual total
  int totalCans = harryShoots + larryShoots - 1;

  // Step 2: Calculate cans not shot by each person
  // For each person, unshot cans = total cans - cans they shot
  int harryUnshot = totalCans - harryShoots;
  int larryUnshot = totalCans - larryShoots;

  return {harryUnshot, larryUnshot};
}

int main() {
  // Step 1: Input
  int harryShots, larryShots;
  cin >> harryShots >> larryShots;

  // Step 2: Validate input
  if (harryShots < 0 || larryShots < 0) {
    cout << "Invalid input: shots cannot be negative" << endl;
    return 1;
  }

  // Step 3: Check if total cans would exceed 10
  if (harryShots + larryShots - 1 > 10) {
    cout << "Invalid scenario: total cans would exceed 10" << endl;
    return 1;
  }

  // Step 4: Check if scenario is possible
  int totalCans = harryShots + larryShots - 1;
  if (totalCans < harryShots || totalCans < larryShots) {
    cout << "Invalid scenario: not enough cans" << endl;
    return 1;
  }

  // Solve and output
  pair<int, int> result = solveCanShooting(harryShots, larryShots);
  cout << result.first << " " << result.second << endl;
  return 0;
}
