export function canSumTabu(targetSum: number, numbers: number[]) {
  // create an array of size targetSum + 1
  // initialize the array with false
  const table = new Array(targetSum + 1).fill(false);
  // set the 0th index to true
  table[0] = true;
  // for each number in the table
  for (let i = 0; i <= targetSum; i++) {
    if (table[i] === true) {
      //   for each number in the table
      for (let num of numbers) {
        if (i + num > targetSum) continue;
        table[i + num] = true;
      }
    }
  }
  return table[targetSum];
}

// space and time complexity
// time: O(n * m)
// space: O(m)
