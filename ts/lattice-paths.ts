// Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
// a diagram of 6 2 by 2 grids showing all the routes to the bottom right corner
//
// How many such routes are there through a given gridSize?

// latticePaths(4) -> 70

/// In this lattice path problem:
// - The starting point is at the top-left corner (not inside the first box)
// - We count paths to the bottom-right corner (not inside the last box)
// - For a gridSize of n, we're essentially solving for an (n+1) x (n+1) grid of boxes
//
// Note: The number of paths in an n x n corner-to-corner grid
// is equal to the number of paths in an (n-1) x (n-1) box-to-box grid
//
// Example:
// - A 2x2 corner-to-corner grid (3x3 box grid) has 6 possible paths
// - This is equivalent to paths in a 3x3 box-to-box grid (4x4 corner grid)
//
// Therefore, our formula uses 2n for total moves, where n is the given gridSize/ possibilities equal with 3x3 box biased versus 2x2 corner biased

export function latticePaths(gridSize: number): number {
  return calculateCombination(gridSize * 2, gridSize);
}

function calculateCombination(n: number, k: number): number {
  // Calculate C(n,k) = n! / (k! * (n-k)!)
  // https://en.wikipedia.org/wiki/Binomial_coefficient
  let result = 1;
  for (let i = 1; i <= k; i++) {
    result *= (n - k + i) / i;
  }
  return Math.round(result);
}
