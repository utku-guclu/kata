import { multiplicationTable } from "../multi-table";

describe("multiplicationTable", () => {
  it("should return a multiplication table", () => {
    expect(multiplicationTable(3)).toEqual([
      [1, 2, 3],
      [2, 4, 6],
      [3, 6, 9],
    ]);
  });
});
