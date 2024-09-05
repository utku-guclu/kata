function floorSqrt(x) {
  if (x === 0) {
    return 0;
  }

  let left = 1;
  let right = x;
  let result = 0;

  while (left <= right) {
    let mid = Math.floor((left + right) / 2);

    if (mid * mid === x) {
      return mid;
    } else if (mid * mid < x) {
      result = mid; // Store the result and continue searching for a larger one
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return result;
}

module.exports = floorSqrt;
