/* 1. Read number of test cases N
2. For each test case:
   - Read position (e.g., "a1")
   - Convert position to board coordinates (row, col)
   - Count possible knight moves:
     * Define 8 possible knight moves
     * For each move:
       - Calculate new position
       - If new position is on board (valid)
         * Increment counter
   - Output the count */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Position {
  int row, col;
};

// All possible knight moves
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

Position convertPosition(string pos) {
  Position p;
  p.row = pos[0] - 'a'; // convert a to 0 etc.
  p.col = pos[1] - '1'; // convert 1 to 0 etc.
  return p;
}

bool isValid(int row, int col) {
  return (row >= 0 && row < 8 && col >= 0 && col < 8);
}

int countKnightMoves(Position p) {
  int count = 0; // total possible knight moves

  // check all 8 possible moves
  for (int i = 0; i < 8; i++) {
    int newRow = p.row + dx[i];
    int newCol = p.col + dy[i];

    if (isValid(newRow, newCol))
      count++;
  }
  return count;
}

int main() {
  int N; // number of test cases
  cin >> N;

  vector<int> results(N); // or int results[N];

  // Read each test case
  for (int i = 0; i < N; i++) {
    string pos;
    cin >> pos;
    Position p = convertPosition(pos);
    results[i] = countKnightMoves(p);
    /*     cout << p.row << " " << p.col << "\n"; */
  }
  // Output results
  for (int i = 0; i < N; i++) {
    cout << results[i] << "\n";
  }
  return 0;
}
