export function powerDigitSum(exponent: number): number {
  // Calculate 2^exponent using Big Integers
  let result = BigInt(2) ** BigInt(exponent);
  // https://en.wikipedia.org/wiki/Power_digit_sum

  let sum = 0;
  let resultStr = result.toString();
  for (let char of resultStr) {
    sum += Number(char);
  }
  // let base = 2;
  // for (let i = 1; i < exponent; i++) {
  //   base *= 2;
  // }

  // while (base > 0) {
  //   sum += base % 10;
  //   base = Math.floor(base / 10);
  // }

  return sum;
}

powerDigitSum(4);
