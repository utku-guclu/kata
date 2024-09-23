// m x n grid. Find the possibilities of ending the last row and last column using to right and down option
// create a 2D array
// initialize m x n array with 0
// initialize 1 x 1 array with 1
// distrubute to right and down it's value is sum of right and down
// return the last element of the array
//
//// binomial coefficent formula for m x n grid: (m + n - 2)! / ((m - 1)! * (n - 1)!)

export function gtTabu(m: number, n: number) {
  if (m === 0 || n === 0) return 0;
  const table = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
  table[1][1] = 1;

  for (let i = 0; i <= m; i++) {
    for (let j = 0; j <= n; j++) {
      if (i + 1 <= m) table[i + 1][j] += table[i][j];
      if (j + 1 <= n) table[i][j + 1] += table[i][j];
    }
  }
  return table[m][n];
}

// Time and space complexity
// time: O(m * n)
// space: O(m * n)
