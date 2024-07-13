import { longestCollatzSequence } from "../longest-collatz-sequence";

describe("lcs", () => {
  it("should give max", () => {
    expect(longestCollatzSequence(14)).toBe(9);
  });
});
