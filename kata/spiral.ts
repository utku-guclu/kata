export function centralSpiral(n: number) {
  // Create an n x n array filled with zeros
  const spiral: number[][] = Array(n)
    .fill(null)
    .map(() => Array(n).fill(0));

  let num: number = 1;
  let row = Math.floor(n / 2);
  let col = Math.floor(n / 2);

  // Place 1 at the center
  spiral[row][col] = num++;

  // Direction vectors: right, down, left, up
  const dr = [0, 1, 0, -1];
  const dc = [1, 0, -1, 0];

  let steps = 1;
  let dir = 0;

  // This the main loop that continues until we've filled all cells in the n x n array
  while (num <= n * n) {
    // This loop runs twice for each "arm" of the spiral. It's responsible for making the spiral turn corners.
    for (let i = 0; i < 2; i++) {
      // This inner loop moves in the current direction for a number of steps equal to the current arm length.
      for (let step = 0; step < steps; step++) {
        row += dr[dir];
        col += dc[dir];
        if (row >= 0 && row < n && col >= 0 && col < n) {
          spiral[row][col] = num++;
        }
        // if (num > n * n) break;
      }
      dir = (dir + 1) % 4;
    }
    steps++;
  }

  return spiral;
}

function printSpiral(spiral: number[][]) {
  const cellWidth = Math.max(...spiral.flatMap((row) => row.toString().length));
  spiral.forEach((row) => {
    console.log(
      row.map((num) => num.toString().padStart(cellWidth, " ")).join(" "),
    );
  });
}

export function sumDiagonal(spiral: number[][]) {
  // Initialize sum to -1 for odd-length spirals to account for double counting the center element
  let sum = spiral.length % 2 === 0 ? 0 : -1;
  for (let i = 0; i < spiral.length; i++) {
    sum += spiral[i][i];
    sum += spiral[i][spiral.length - 1 - i];
  }
  return sum;
}

// Test cases
console.log("2x2 spiral:");
printSpiral(centralSpiral(2)); // [[3, 4], [2, 1]]

console.log("sum of diagonals:");
console.log(sumDiagonal(centralSpiral(2))); // 10
