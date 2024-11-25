#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int shortestCellPath(const vector<vector<int>> &grid, int sr, int sc, int tr,
                     int tc) {
  int rows = grid.size();
  int cols = grid[0].size();

  if (grid[sr][sc] == 0 || grid[tr][tc] == 0) {
    return -1;
  }

  // up - right - down - left
  vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  // queue for BFS: {row, col, distance}
  queue<pair<pair<int, int>, int>> q;
  q.push({{sr, sc}, 0});

  vector<vector<bool>> visited(rows, vector<bool>(cols, false));
  visited[sr][sc] = true;

  while (!q.empty()) {
    int row = q.front().first.first;
    int col = q.front().first.second;
    int dist = q.front().second;
    q.pop();

    if (row == tr && col == tc) {
      return dist;
    }

    for (const auto &dir : directions) {
      int r = row + dir.first;
      int c = col + dir.second;

      if (r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == 1 &&
          !visited[r][c]) {
        q.push({{r, c}, dist + 1});
        visited[r][c] = true;
      }
    }
  }

  return -1;
}

int main() {
  vector<vector<int>> grid = {{1, 1, 1, 1}, {0, 0, 0, 1}, {1, 1, 1, 1}};
  int sr = 0, sc = 0, tr = 2, tc = 0;
  cout << shortestCellPath(grid, sr, sc, tr, tc) << endl;
  return 0;
}
