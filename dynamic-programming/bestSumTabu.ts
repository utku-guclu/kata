export function howSum(targetSum: number, numbers: number[]): number[] | null {
  const dp = new Array(targetSum + 1).fill(null);
  dp[0] = []; // Base case: To make 0, use an empty array.

  for (let i = 0; i <= targetSum; i++) {
    if (dp[i] !== null) {
      for (const num of numbers) {
        const combination = [...dp[i], num];
        if (!dp[i + num] || dp[i + num].length > combination.length) {
          dp[i + num] = combination;
        }
      }
    }
  }

  return dp[targetSum]; // Return the result for the targetSum.
}

const res = howSum(4, [1, 2, 3]); // Example call
console.log(res); // Output: [3, 5] or [5, 3] or any valid combination
