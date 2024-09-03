export function canConstruct(
  target: string,
  wordBank: string[],
  memo: { [key: string]: boolean } = {},
) {
  if (target in memo) return memo[target];
  if (target === "") return true;

  for (let word of wordBank) {
    // if the word is a prefix of the target
    if (target.indexOf(word) === 0) {
      // slice the word from the target
      const suffix = target.slice(word.length);
      // if the suffix can be constructed
      if (canConstruct(suffix, wordBank, memo) === true) {
        // add the word to the memo
        memo[target] = true;
        return true;
      }
    }
  }
  // if the target cannot be constructed
  memo[target] = false;
  return false;
}

// const res = canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"]);
const res = canConstruct("skateboard", [
  "bo",
  "rd",
  "ate",
  "t",
  "ska",
  "sk",
  "boar",
]);
console.log(res);
