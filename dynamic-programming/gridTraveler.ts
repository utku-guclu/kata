type Memo = Record<string, number>;

export function gridTraveler(m: number, n: number, memo: Memo = {}): number {
  const key1 = `${m},${n}`;
  const key2 = `${n},${m}`;

  const key = key1 + key2;

  if (key in memo) return memo[key];

  if (m === 1 && n === 1) return 1;
  if (m === 0 || n === 0) return 0;

  memo[key] = gridTraveler(m - 1, n, memo) + gridTraveler(m, n - 1, memo);

  return memo[key];
}
