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

TreeNode build(std::vector<int> &a, int i) {
    if (i >= a.size()) return nullptr;

    TreeNode root = new Node(a[i]);
    root->left = build(a, 2 * i + 1);
    root->right = build(a, 2 * i + 2);

    return root;
}

void inorder_travel(TreeNode root) {
    if (!root) return;
    inorder_travel(root->left);
    std::cout << root->value << " ";
    inorder_travel(root->right);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        TreeNode bst = build(a, 0);

        inorder_travel(bst);
        std::cout << "\n";

        delete bst;
    }
}