#include <algorithm>
#include <iostream>
#include <vector>

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

using TreeNode = Node *;

std::vector<int> nodes;

TreeNode insert(TreeNode root, int value) {
    if (!root) return new Node(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

int count_leafs(TreeNode root) {
    if (!root) return 0;

    int sum = 0;

    if (!root->left && !root->right) sum += 1;
    sum += count_leafs(root->left);
    sum += count_leafs(root->right);

    return sum;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        nodes.resize(n);
        for (int i = 0; i < n; ++i) std::cin >> nodes[i];

        TreeNode binary_tree = nullptr;

        for (int node : nodes) {
            binary_tree = insert(binary_tree, node);
        }

        std::cout << n - count_leafs(binary_tree) << "\n";
        delete binary_tree;
    }
}