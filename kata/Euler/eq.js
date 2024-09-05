class TreeNode {
  constructor(val = 0, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

function isIdenticalTree(p, q) {
  // Base case: If both nodes are null, they are identical
  if (!p && !q) {
    return true;
  }

  // If one of the nodes is null and the other isn't, they are not identical
  if (!p || !q) {
    return false;
  }

  // Check if the current nodes have the same value
  if (p.val !== q.val) {
    return false;
  }

  // Recursively check left and right subtrees
  return isIdenticalTree(p.left, q.left) && isIdenticalTree(p.right, q.right);
}

module.exports = { TreeNode, isIdenticalTree };
