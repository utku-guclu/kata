export const digitalRoot = (n: number): number => {
  // base case
  if (n < 10) return n;
  // pre
  const result = accu(n);
  // recursive
  return digitalRoot(result);
};

// reduce number
const accu = (n: number): number => {
  return Array.from(String(n)).reduce((acc, dig) => acc + Number(dig), 0);
};
