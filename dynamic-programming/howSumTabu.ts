export const howSum = (targetSum: number, numbers: number[]) => {
  const table = Array(targetSum + 1).fill(null);
  table[0] = [];

  for (let i = 0; i <= targetSum; i++) {
    if (table[i] !== null) {
      for (let num of numbers) {
        if (i + num <= targetSum) {
          // Add new number at the beginning instead of the end
          table[i + num] = [num, ...table[i]];
        }
      }
    }
  }
  return table[targetSum];
};
