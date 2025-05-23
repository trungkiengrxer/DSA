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

TreeNode insert(TreeNode root, int value) {
    if (!root) return new Node(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

int find_height(TreeNode root) {
    if (!root) return -1;

    int left = find_height(root->left);
    int right = find_height(root->right);

    return std::max(left, right) + 1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> nodes(n);
        for (int i = 0; i < n; ++i) std::cin >> nodes[i];

        TreeNode binary_tree = nullptr;
        for (const int &node : nodes) {
            binary_tree = insert(binary_tree, node);
        }

        std::cout << find_height(binary_tree) << "\n";
        delete binary_tree;
    }
}