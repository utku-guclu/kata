// test fibonacci function with jest
import { fib } from "../fib";

describe("fibonacci", () => {
  it("should return 0 for 0", () => {
    expect(fib(0)).toBe(0);
  });
  it("should return 0 for 0", () => {
    expect(fib(50)).toBe(12586269025);
  });
});
