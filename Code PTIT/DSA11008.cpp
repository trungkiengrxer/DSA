#include <iostream>
#include <memory>
#include <queue>
#include <unordered_map>
#include <unordered_set>

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

bool bfs(TreeNode root) {
    if (!root) return true;

    std::queue<std::pair<TreeNode, int>> queue;
    queue.push({root, 0});
    int leaf_level = -1;

    while (!queue.empty()) {
        auto [node, level] = queue.front();
        queue.pop();

        if (!node->left && !node->right) {
            if (leaf_level == -1)
                leaf_level = level;
            else if (leaf_level != level)
                return false;
        }

        if (node->left) queue.push({node->left, level + 1});
        if (node->right) queue.push({node->right, level + 1});
    }

    return true;
}


int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::unordered_map<int, TreeNode> nodes;
        std::unordered_set<int> children;

        for (int i = 1; i <= n; ++i) {
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

        TreeNode root = nullptr;
        for (auto &[value, node] : nodes) {
            if (children.find(value) == children.end()) {
                root = node;
                break;
            }
        }

        if (bfs(root))
            std::cout << "1\n";
        else
            std::cout << "0\n";
    }
}