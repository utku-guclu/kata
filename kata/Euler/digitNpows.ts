// Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits: 1634 = 14 + 64 + 34 + 44 8208 = 84 + 24 + 04 + 84 9474 = 94 + 44 + 74 + 44 As 1 = 14 is not a sum it is not included. The sum of these numbers is 1634 + 8208 + 9474 = 19316. Find the sum of all the numbers that can be written as the sum of n powers of their digits.

// This is an interesting mathematical problem! Let's approach it step-by-step:
//
// First, we need to understand what the question is asking:
//
// We're looking for numbers that are equal to the sum of their digits raised to some power n.
// We need to find all such numbers for all possible values of n.
// Then, we need to sum all these numbers.
//
//
// Let's think about the limits:
//
// The lower limit for n is 1, as n = 0 would make no sense in this context.
// For the upper limit, we need to consider when a number can no longer be equal to the sum of its digits raised to n.
//
//
// Let's consider the largest single-digit number, 9:
//
// 9^1 = 9
// 9^2 = 81
// 9^3 = 729
// 9^4 = 6561
// 9^5 = 59049
// 9^6 = 531441
// 9^7 = 4782969
//
//
// We can see that 9^7 is a 7-digit number. This means that for any n ≥ 7, even the largest possible single-digit number raised to that power will result in a number with fewer digits than n. Therefore, we only need to check up to n = 6.

function digitNpows(num: number, n: number): boolean {
  let sum = 0;
  for (let dig of num.toString()) {
    sum += Math.pow(parseInt(dig), n);
  }
  return num === sum;
}

function findAllNums(n: number = 0): number[] {
  let result = [];
  // for (let n = 1; n <= 6; n++) {
  // The maximum possible number is 9^n * number of digits
  let maxNum = Math.pow(9, n) * Math.pow(9, n).toString().length;
  for (let num = 2; num <= maxNum; num++) {
    if (digitNpows(num, n)) {
      result.push(num);
    }
  }
  // }
  return result;
}

function solve(n: number): number {
  const numbers = findAllNums(n);
  return numbers.reduce((a, b) => a + b, 0);
}

// Example usage:
const n = 4; // You can change this to any n you want to check
const res = solve(n);
console.log(`Sum of all numbers for n=${n}: ${res}`);

// If you want to see all the numbers found:
const allNumbers = findAllNums(n);
console.log(`All numbers found for n=${n}:`, allNumbers);
