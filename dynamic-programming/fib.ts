type Memo = {
  [key: number]: number;
};

export function fib(n: number, memo: Memo = {}): number {
  if (n <= 1) return n;

  if (memo[n]) return memo[n];

  memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
  return memo[n];
}
