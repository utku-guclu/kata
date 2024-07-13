import { latticePaths } from "../lattice-paths";

describe("latticePaths", () => {
  it("should return", () => {
    expect(latticePaths(4)).toBe(70);
  });
});
