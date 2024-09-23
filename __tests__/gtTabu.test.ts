import { gtTabu } from "../dynamic-programming/gridTraverelerTabu";

describe("gtTabu", () => {
  it("should return 0", () => {
    expect(gtTabu(0, 0)).toBe(0);
  });
  it("should return 1", () => {
    expect(gtTabu(1, 1)).toBe(1);
  });
  it("should return 55", () => {
    expect(gtTabu(10, 10)).toBe(48620);
  });
});

// to run test command: npm test
// space and time complexity:
// space: O(m * n)
// time: O(m * n)
//
