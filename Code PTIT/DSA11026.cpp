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

TreeNode build(int left, int right) {
    if (left > right) return nullptr;

    int mid = (left + right) / 2;
    TreeNode root = new Node(nodes[mid]);
    root->left = build(left, mid - 1);
    root->right = build(mid + 1, right);

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
        int n;
        std::cin >> n;

        nodes.resize(n);
        for (int i = 0; i < n; ++i) std::cin >> nodes[i];

        std::sort(nodes.begin(), nodes.end());
        TreeNode balanced_bst = build(0, n - 1);

        postorder_travel(balanced_bst);
        std::cout << "\n";
        delete balanced_bst;
    }
}