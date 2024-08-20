export const vectorAffinity = function vectorAffinity(
  xs: Array<number | null>,
  ys: Array<number | null>,
): number {
  // Handle cases where one or both arrays are empty
  if (xs.length === 0 || ys.length === 0) {
    return xs.length === ys.length ? 1.0 : 0.0;
  }

  // Determine the length of the longer vector
  const maxLength = Math.max(xs.length, ys.length);

  // Initialize a counter for matching elements
  let match = 0;

  // Iterate through the longer vector
  for (let i = 0; i < maxLength; i++) {
    const xVal = xs[i] === undefined ? null : xs[i];
    const yVal = ys[i] === undefined ? null : ys[i];

    if (xVal === yVal) {
      match += 1; // Increment match counter for each matching pair
    }
  }

  // Calculate affinity based on the length of the longer vector
  return parseFloat((match / maxLength).toFixed(1));
};

// test
// vectorAffinity([null],[null,null]): expected 1 to be close to 0.5 +/- 1e-8

// const res = vectorAffinity([null], [null, null]);
const res = vectorAffinity([1, 2, 3, 4], [1, 2, 3, 5]);
console.log(res);
