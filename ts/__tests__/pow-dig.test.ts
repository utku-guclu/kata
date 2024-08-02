import { powerDigitSum } from "../pow-dig";

describe("powerDigitSum", () => {
  it("should return 16", () => {
    expect(powerDigitSum(4)).toBe(7);
  });
  it("should return 166", () => {
    expect(powerDigitSum(128)).toBe(166);
  });
});
