const compress = require("./ex");

test("comprees aabcc to 2a1b2c", () => {
  expect(compress("aabcc")).toBe("2a1b2c");
});
