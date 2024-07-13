export function longestCollatzSequence(limit: number): number {
  let longestChain = 0;
  let numberWithLongestChain = 0;

  for (let i = 1; i <= limit; i++) {
    const chainLength = helper(i);
    if (chainLength > longestChain) {
      longestChain = chainLength;
      numberWithLongestChain = i;
    }
  }
  return numberWithLongestChain;
}

function helper(n: number, count: number = 1): number {
  if (n === 1) return count;

  if (n % 2 === 0) {
    return helper(n / 2, count + 1);
  } else {
    return helper(3 * n + 1, count + 1);
  }
}

longestCollatzSequence(14);
