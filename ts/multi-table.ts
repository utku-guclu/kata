export function multiplicationTable(size: number): number[][] {
  // Implement me! :)
  let result: number[][] = [];
  for (let i = 1; i <= size; i++) {
    let row: number[] = [];
    for (let j = 1; j <= size; j++) {
      row.push(multiply(i, j));
    }
    result.push(row);
  }
  return result;
}

function multiply(a: number, b: number): number {
  return a * b;
}

const res = multiplicationTable(3);
console.log(res);
