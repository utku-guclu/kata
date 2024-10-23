import { howSum } from "../dynamic-programming/howSumTabu";

describe("howSum", () => {
  it("should return true", () => {
    expect(howSum(7, [5, 4, 4, 7])).toEqual([7]);
  });
  it("should return true", () => {
    expect(howSum(8, [6, 3, 5])).toEqual([3, 5]);
  });
  it("should return true", () => {
    expect(howSum(300, [7, 14])).toEqual(null);
  });
});
