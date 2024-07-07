// digitalRoot.test.ts
import { digitalRoot } from "../digitalRoot";

describe("digitalRoot", () => {
  it("should return the sum of digits", () => {
    expect(digitalRoot(123)).toBe(6);
    expect(digitalRoot(456)).toBe(6);
    expect(digitalRoot(789)).toBe(6);
  });

  it("should return 0 for an empty string", () => {
    expect(digitalRoot(0)).toBe(0);
  });

  it("should handle a single digit correctly", () => {
    expect(digitalRoot(5)).toBe(5);
  });
});
