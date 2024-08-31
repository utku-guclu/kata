import { centralSpiral, sumDiagonal } from "../kata/spiral";

describe("spiral", () => {
  it("should give max", () => {
    expect(centralSpiral(2)).toEqual([
      [3, 4],
      [2, 1],
    ]);
  });
  it("should give max", () => {
    expect(sumDiagonal(centralSpiral(2))).toBe(10);
  });
});
