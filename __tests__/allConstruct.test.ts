import { allConstruct } from "../dynamic-programming/allConstruct";

describe("allConstruct", () => {
  it("should return all possible combinations of target string", () => {
    const target = "abcdef";
    const wordBank = ["ab", "abc", "cd", "def", "abcd", "ef", "c"];
    expect(allConstruct(target, wordBank)).toEqual([
      ["ab", "cd", "ef"],
      ["ab", "c", "def"],
      ["abc", "def"],
      ["abcd", "ef"],
    ]);
  });
});
