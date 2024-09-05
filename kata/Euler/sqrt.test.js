const sqrt = require("./sqrt");

test("floor sqrt", () => {
  expect(sqrt(17)).toBe(4);
});

test("sqrt", () => {
  expect(sqrt(16)).toBe(4);
});
