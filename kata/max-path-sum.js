function maximumPathSumI(triangle) {
  // Create a copy of the triangle to avoid modifying the original input
  const pathSums = triangle.map((row) => row.slice());
  // Start from the second-to-last row and move upwards
  for (let i = pathSums.length - 2; i >= 0; i--) {
    for (let j = 0; j <= i; j++) {
      // Add the larger of the two numbers below
      pathSums[i][j] += Math.max(pathSums[i + 1][j], pathSums[i + 1][j + 1]);
    }
  }
  // The top element now contains the maximum sum
  return pathSums[0][0];
}

const res = maximumPathSumI([
  [3, 0, 0, 0],
  [7, 4, 0, 0],
  [2, 4, 6, 0],
  [8, 5, 9, 3],
]);
console.log(res);
