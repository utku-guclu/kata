const nums = [2, 3, 0, 4, 8]; // Expected output: [0, 2, 3, 4, 8]

function Part(arr, hi, lo) {
  let piv = arr[hi];
  let idx = lo - 1;

  for (let j = lo; j < hi; j++) {
    if (arr[j] < piv) {
      idx++;
      [arr[j], arr[idx]] = [arr[idx], arr[j]];
    }
  }
  [arr[hi], arr[idx + 1]] = [arr[idx + 1], arr[hi]];
  return idx + 1;
}

function QS(arr, lo, hi) {
  if (lo >= hi) return;
  const piv = Part(arr, hi, lo);
  QS(arr, lo, piv - 1);
  QS(arr, piv + 1, hi);
}

QS(nums, 0, nums.length - 1);
console.log(nums); // Output: [0, 2, 3, 4, 8]
