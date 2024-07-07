function getProduct(arr, x, y, dx, dy) {
  let product = 1;
  for (let i = 0; i < 4; i++) {
    if (x < 0 || x >= arr.length || y < 0 || y >= arr[0].length) return -1;
    product *= arr[x][y];
    x += dx;
    y += dy;
  }
  return product;
}

function largestGridProduct(arr) {
  function recursiveSearch(x, y, maxProduct) {
    if (x >= arr.length || y >= arr[0].length) return maxProduct;

    // Directions: right, down, diagonal right-down, diagonal left-down
    const directions = [
      [0, 1],
      [1, 0],
      [1, 1],
      [1, -1],
    ];
    for (const [dx, dy] of directions) {
      const product = getProduct(arr, x, y, dx, dy);
      maxProduct = Math.max(maxProduct, product);
    }

    // Move to the next cell
    if (y < arr[0].length - 1) {
      return recursiveSearch(x, y + 1, maxProduct);
    } else {
      return recursiveSearch(x + 1, 0, maxProduct);
    }
  }

  return recursiveSearch(0, 0, -Infinity);
}

// Test the function with the provided grid
const testGrid = [
  [40, 17, 81, 18, 57],
  [74, 4, 36, 16, 29],
  [36, 42, 69, 73, 45],
  [51, 54, 69, 16, 92],
  [7, 97, 57, 32, 16],
];

console.log(largestGridProduct(testGrid)); // Output the greatest product
