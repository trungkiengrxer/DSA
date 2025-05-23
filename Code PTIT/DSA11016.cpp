#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<int> values;

struct Node {
    int value;
    Node *left;
    Node *right;

    Node(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

typedef Node *TreeNode;

void delete_tree(TreeNode root) {
    if (!root) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

void store(TreeNode root) {
    if (!root) return;
    store(root->left);
    values.push_back(root->value);
    store(root->right);
}

void assign(TreeNode root, int &index) {
    if (!root) return;
    assign(root->left, index);
    root->value = values[index++];
    assign(root->right, index);
}

void print(TreeNode root) {
    if (!root) return;
    print(root->left);
    std::cout << root->value << " ";
    print(root->right);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, index = 0;
        std::cin >> n;

        values.clear();
        std::unordered_map<int, TreeNode> nodes;
        std::unordered_set<int> children;

        for (int i = 0; i < n; ++i) {
            int u, v;
            char x;
            std::cin >> u >> v >> x;

            if (!nodes[u]) nodes[u] = new Node(u);
            if (!nodes[v]) nodes[v] = new Node(v);

            if (x == 'L')
                nodes[u]->left = nodes[v];
            else
                nodes[u]->right = nodes[v];

            children.insert(v);
        }

        TreeNode tree = nullptr;

        for (const auto &[value, node] : nodes) {
            if (children.find(value) == children.end()) {
                tree = node;
                break;
            }
        }

        store(tree);
        std::sort(values.begin(), values.end());
        assign(tree, index);

        print(tree);
        std::cout << "\n";

        delete_tree(tree);
    }
}