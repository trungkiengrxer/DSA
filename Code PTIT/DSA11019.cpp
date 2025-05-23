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

TreeNode build(int start, int end, int &index) {
    if (index >= nodes.size()) return nullptr;

    int value = nodes[index];
    if (value < start || value > end) return nullptr;

    ++index;
    TreeNode root = new Node(value);
    root->left = build(start, value - 1, index);
    root->right = build(value + 1, end, index);

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

    while (t--) {
        int n, index = 0;
        std::cin >> n;

        nodes.resize(n);
        for (int i = 0; i < n; ++i) std::cin >> nodes[i];

        int start = *std::min_element(nodes.begin(), nodes.end());
        int end = *std::max_element(nodes.begin(), nodes.end());

        TreeNode binary_tree = build(start, end, index);

        postorder_travel(binary_tree);
        std::cout << "\n";

        delete binary_tree;
    }
}