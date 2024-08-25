export function canSum(
  targetSum: number,
  numbers: Array<number>,
  memo: { [key: number]: boolean } = {},
): boolean {
  if (targetSum === 0) return true;
  if (targetSum < 0) return false;
  if (targetSum in memo) return memo[targetSum];

  for (let num of numbers) {
    if (canSum(targetSum - num, numbers, memo)) {
      memo[targetSum] = true;
      return true;
    }
  }

  memo[targetSum] = false;
  return false;
}
