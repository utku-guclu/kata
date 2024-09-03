export function bestSum(
  nums: number[],
  targetSum: number,
  memo: { [key: number]: number[] | null } = {},
): number[] | null {
  if (targetSum in memo) return memo[targetSum];

  if (targetSum === 0) return [];
  if (targetSum < 0) return null;

  let shortestCombination: number[] | null = null;

  for (let num of nums) {
    const remainder = targetSum - num;
    const remainderResult = bestSum(nums, remainder, memo);
    if (remainderResult !== null) {
      const combination = [...remainderResult, num];
      // if the combination is shorter than the current shortest combination, update it
      if (
        shortestCombination === null ||
        combination.length < shortestCombination.length
      ) {
        shortestCombination = combination;
      }
    }
  }
  memo[targetSum] = shortestCombination;
  return shortestCombination;
}

// console.log(bestSum([7, 14], 300)); // null
console.log(bestSum([5, 3, 4, 7], 7)); // [7]
