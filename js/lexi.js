function getPermutations(array) {
  if (array.length === 0) return [[]];
  let result = [];
  for (let i = 0; i < array.length; i++) {
    let currentNum = array[i];
    let remainingNums = array.slice(0, i).concat(array.slice(i + 1));
    let remainingPerms = getPermutations(remainingNums);
    for (let perm of remainingPerms) {
      result.push([currentNum].concat(perm));
    }
  }
  return result;
}

function solve() {
  const target = 1000000;
  const rangeLimit = 10;
  const digitsArray = Array.from({ length: rangeLimit }, (_, i) => i);

  // Get all permutations of the digits
  const digitPermutations = getPermutations(digitsArray);

  // Get the millionth permutation (0-indexed so subtract 1)
  const digits = digitPermutations[target - 1];

  // Convert the array of digits back to a number
  const answer = digits.reduce(
    (acc, digit, i) => acc + digit * 10 ** (rangeLimit - 1 - i),
    0,
  );

  return answer;
}

const expectedAnswer = 2783915460;
console.log("Answer:", solve()); // Should output: 2783915460
