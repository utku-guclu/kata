export function howSum(
  targetSum: number,
  numbers: Array<number>,
  memo: { [key: number]: Array<number> | null } = {},
): Array<number> | null {
  if (targetSum in memo) return memo[targetSum];

  if (targetSum === 0) return [];
  if (targetSum < 0) return null;

  for (let num of numbers) {
    const remainder = targetSum - num;
    const remainderResult = howSum(remainder, numbers, memo);
    if (remainderResult !== null) {
      memo[targetSum] = [...remainderResult, num];
      return memo[targetSum];
    }
  }
  memo[targetSum] = null;
  return null;
}

const res = howSum(7, [5, 3, 4, 7]);
const res2 = howSum(111, [8, 6, 4]); //null
console.log(res2);
