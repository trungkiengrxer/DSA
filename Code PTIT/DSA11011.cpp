#include <iostream>
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

    std::queue<TreeNode> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode node = queue.front();
        queue.pop();

        bool has_left = true;
        if (!node->left) has_left = false;
        bool has_right = true;
        if (!node->right) has_right = false;

        if ((!has_left && has_right) || (has_left && !has_right)) return false;

        if (has_left) queue.push(node->left);
        if (has_right) queue.push(node->right);
    }

    return true;
}

void delete_tree(TreeNode root) {
    if (!root) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

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

        std::cout << bfs(tree) << "\n";
        delete_tree(tree);
    }
}