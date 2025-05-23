#include <iostream>
#include <vector>
#include <memory>

struct Node {
    int value;
    Node *left;
    Node *right;

    Node(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }

    ~Node() {
        delete left;
        delete right;
    }
};

using TreeNode = Node*;

TreeNode insert(TreeNode root, int value) {
    if (!root) return new Node(value);

    if (value < root->value) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);

    return root;
}

void preorder_travel(TreeNode root) {
    if (!root) return;

    std::cout << root->value << " ";
    preorder_travel(root->left);
    preorder_travel(root->right);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> nodes(n);

        TreeNode tree = nullptr;

        for (int i = 0; i < n; ++i) {
            int value;
            std::cin >> value;
            tree = insert(tree, value);
        }

        preorder_travel(tree);
        std::cout << "\n";
        delete tree;
    }
}