import { canSumTabu } from "../dynamic-programming/canSumTabu";

describe("canSumTabu", () => {
  it("should return false", () => {
    expect(canSumTabu(7, [2, 3])).toBe(true);
  });
  it("should return true", () => {
    expect(canSumTabu(2, [5, 3, 4, 7, 1, 1])).toBe(true);
  });
  it("should return true", () => {
    expect(canSumTabu(7, [2, 4])).toBe(false);
  });
  it("should return false", () => {
    expect(canSumTabu(8, [2, 3, 5])).toBe(true);
  });
});
