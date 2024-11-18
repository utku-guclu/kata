class Solution {
  public countPaths(n: number): number {
    // Start from bottom left (matrix[n-1][0])
    return this.#dfs(n - 1, 0, n);
  }

  #isValid(row: number, col: number, n: number): boolean {
    // Check boundaries
    return row >= 0 && row < n && col >= n - 1 - row && col < n;
  }

  #dfs(row: number, col: number, n: number): number {
    if (!this.#isValid(row, col, n)) {
      console.log(`Invalid cell: (${row}, ${col})`);
      return 0;
    } // Base case 1: Out of bounds

    if (row === 0 && col === n - 1) {
      console.log(`Found path: (${row}, ${col})`);
      return 1;
    } // Base case 2: Reach the top right corner

    // Try all possible moves (right and down)
    console.log(`Exploring cell: (${row}, ${col})`);
    // and add their results
    console.log("Trying up...");
    const upPaths: number = this.#dfs(row - 1, col, n); // Move down
    console.log("Trying right...");
    const rightPaths: number = this.#dfs(row, col + 1, n); // Move right

    return upPaths + rightPaths;
  }
}

// Test with visualization
function visualizeGrid(n: number): void {
  console.log(`\nGrid ${n}x${n}:`);
  for (let i = 0; i < n; i++) {
    let row = "";
    for (let j = 0; j < n; j++) {
      if (j < n - 1 - i) {
        row += "🟦 ";
      } else {
        row += "⬜ ";
      }
    }
    row += `  row=${i}`;
    console.log(row);
  }
  console.log();
}

// Test
const N = 4;
visualizeGrid(N);
console.log(
  `Number of paths for ${N}x${N} grid:`,
  new Solution().countPaths(N),
);
