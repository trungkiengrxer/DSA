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

void postorder_travel(TreeNode root) {
    if (!root) return;
    postorder_travel(root->left);
    postorder_travel(root->right);
    std::cout << root->value << " ";
}

int main() {
    int t;
    std::cin >> t;

    for (int k = 1; k <= t; ++k) {
        int n;
        std::cin >> n;
        nodes.resize(n);

        for (int i = 0; i < n; ++i) std::cin >> nodes[i];

        TreeNode bst = nullptr;

        for (int value : nodes) {
            bst = insert(bst, value);
        }

        std::cout << "Test #" << k << ": ";
        postorder_travel(bst);
        std::cout << "\n";

        delete bst;
    }
}