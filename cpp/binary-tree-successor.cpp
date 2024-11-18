#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *parent;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *findMin(TreeNode *node) {
  while (node->left) {
    node = node->left;
  }
  return node;
}

TreeNode *findSuccessor(TreeNode *node) {
  // If right subtree exists, find leftmost node in right subtree
  if (node->right) {
    return findMin(node->right);
  }

  // If no right subtree exist, go up until finding first right turn
  TreeNode *current = node;
  TreeNode *parent = current->parent;

  while (parent && parent->right == current) {
    current = parent;
    parent = parent->parent;
  }

  return parent;
}

// test
int main() {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(6);
  root->right = new TreeNode(9);
  root->left->parent = root;
  root->right->parent = root;
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(7);
  root->left->left->parent = root->left;
  root->left->right->parent = root->left;

  TreeNode *successor = findSuccessor(root->left);
  if (successor) {
    std::cout << "Successor of " << root->left->val << " is " << successor->val
              << "\n";
  } else {
    std::cout << "No successor found for " << root->left->val << "\n";
  }
  return 0;
}
