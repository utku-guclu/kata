import { howSum } from "../../../dynamic-programming/howSum";

describe("howSum", () => {
  it("should return true for 7", () => {
    expect(howSum(7, [3, 4, 5])).toEqual([4, 3]);
  });
  it("null cases", () => {
    expect(howSum(6, [8, 4, 5])).toBeNull();
    expect(howSum(111, [8, 4, 6])).toBeNull();
  });
});
