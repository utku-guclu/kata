import { gridTraveler } from "../../../dynamic-programming/gridTraveler";

describe("gridTraveler", () => {
  it("should return 0 for 0", () => {
    expect(gridTraveler(0, 0, {})).toBe(0);
  });
  it("should return 0 for 0", () => {
    expect(gridTraveler(1, 1, {})).toBe(1);
  });
  it("should return 0 for 0", () => {
    expect(gridTraveler(2, 3, {})).toBe(3);
  });
  it("should return 0 for 0", () => {
    expect(gridTraveler(3, 2, {})).toBe(3);
  });
  it("should return 0 for 0", () => {
    expect(gridTraveler(3, 3, {})).toBe(6);
  });
  it("should return 0 for 0", () => {
    expect(gridTraveler(18, 18, {})).toBe(2333606220);
  });
});
