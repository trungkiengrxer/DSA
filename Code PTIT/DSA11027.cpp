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

int count_leafs(TreeNode root) {
    if (!root) return 0;

    int count = 0;
    if (!root->left && !root->right) ++count;
    
    count += count_leafs(root->left);
    count += count_leafs(root->right);

    return count;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        nodes.resize(n);
        for (int i = 0;  i < n; ++i) std::cin >> nodes[i];

        std::sort(nodes.begin(), nodes.end());
        TreeNode balanced_bst = build(0, n - 1);

        std::cout << count_leafs(balanced_bst) << "\n";
        delete balanced_bst;
    }
}