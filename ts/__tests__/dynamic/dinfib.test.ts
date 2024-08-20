// test fibonacci function with jest
import { fib } from "../../../dynamic-programming/fib";

describe("fibonacci", () => {
  it("should return 0 for 0", () => {
    expect(fib(0, {})).toBe(0);
  });
  it("should return 0 for 0", () => {
    expect(fib(4, {})).toBe(3);
  });
  it("should return 0 for 0", () => {
    expect(fib(6, {})).toBe(8);
  });
  it("should return 0 for 0", () => {
    expect(fib(50, {})).toBe(12586269025);
  });
});
