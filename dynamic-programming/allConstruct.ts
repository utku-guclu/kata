export function allConstruct(
  target: string,
  wordBank: string[],
  memo: Record<string, string[][]> = {},
): string[][] {
  if (target in memo) return memo[target];
  if (target === "") return [[]];

  const result: string[][] = [];

  for (let word of wordBank) {
    if (target.indexOf(word) === 0) {
      const suffix = target.slice(word.length);
      const suffixWays = allConstruct(suffix, wordBank, memo);
      const targetWays = suffixWays.map((way: string[]) => [word, ...way]);
      result.push(...targetWays);
    }
  }
  memo[target] = result;
  return result;
}
