import { fibTabu } from "../dynamic-programming/fibTabu";

describe("fibTabu", () => {
  it("should return 0", () => {
    expect(fibTabu(0)).toBe(0);
  });
  it("should return 1", () => {
    expect(fibTabu(1)).toBe(1);
  });
  it("should return 55", () => {
    expect(fibTabu(10)).toBe(55);
  });
});

// space and time complexity:
// space: O(n)
// time: O(n)
