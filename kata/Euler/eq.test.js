const { isIdenticalTree, TreeNode } = require("./eq");

// Example usage:
let tree1 = new TreeNode(1);
tree1.left = new TreeNode(2);
tree1.right = new TreeNode(3);

let tree2 = new TreeNode(1);
tree2.left = new TreeNode(2);
tree2.right = new TreeNode(3);

console.log(isIdenticalTree(tree1, tree2)); // Output: true

// Another example
let tree3 = new TreeNode(1);
tree3.left = new TreeNode(2);

let tree4 = new TreeNode(1);
tree4.right = new TreeNode(2);

console.log(isIdenticalTree(tree3, tree4)); // Output: false

test("true equality", () => {
  expect(isIdenticalTree(tree1, tree2)).toBe(true);
});

test("false equality", () => {
  expect(isIdenticalTree(tree3, tree4)).toBe(false);
});
