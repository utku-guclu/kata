import { canSum } from "../../../dynamic-programming/canSum";

describe("canSum", () => {
  it("should return true for 7", () => {
    expect(canSum(7, [3, 4, 5])).toBe(true);
    expect(canSum(6, [8, 4, 5])).toBe(false);
  });
});
