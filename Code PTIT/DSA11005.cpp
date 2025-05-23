#include <iostream>
#include <unordered_map>
#include <unordered_set>
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

std::vector<int> inorder_nodes;
std::vector<int> level_order_nodes;
std::unordered_map<int, int> inorder_index;

TreeNode build(int start, int end, std::vector<int> &levelorder) {
    if (start > end) return nullptr;

    for (int value : levelorder) {
        int index = inorder_index[value];
        if (index >= start && index <= end) {
            TreeNode root = new Node(value);

            std::vector<int> left, right;
            for (int node : levelorder) {
                int position = inorder_index[node];
                if (position >= start && position < index)
                    left.push_back(node);
                else if (position > index && position <= end)
                    right.push_back(node);
            }

            root->left = build(start, index - 1, left);
            root->right = build(index + 1, end, right);
            return root;
        }
    }

    return nullptr;
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

        inorder_index.clear();
        inorder_nodes.resize(n);
        level_order_nodes.resize(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> inorder_nodes[i];
            inorder_index[inorder_nodes[i]] = i;
        }
        for (int i = 0; i < n; ++i) std::cin >> level_order_nodes[i];

        TreeNode binary_tree = build(0, n - 1, level_order_nodes);

        postorder_travel(binary_tree);
        std::cout << "\n";

        delete binary_tree;
    }
}