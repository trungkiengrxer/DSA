#include <iostream>
#include <memory>
#include <vector>
#include <queue>

struct Node {
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

std::unique_ptr<Node>& find(std::unique_ptr<Node> &node, int target) {
    if (!node || node->value == target) return node;

    auto &left_result = find(node->left, target);
    if (left_result) return left_result;
    return find(node->right, target);
} 

void insert(std::unique_ptr<Node> &node, int u, int v, char dir) {
    if (!node) {
        node = std::make_unique<Node>(u);
    }

    auto &parent = find(node, u);
    if (!parent) return;
    if (dir == 'L' && !parent->left) parent->left = std::make_unique<Node>(v);
    else if (dir == 'R' && !parent->right) parent->right = std::make_unique<Node>(v);
}

void level_order(std::unique_ptr<Node> &root) {
    if (!root) return;

    std::queue<std::unique_ptr<Node>*> queue;
    queue.push(&root);

    while (!queue.empty()) {
        std::unique_ptr<Node> &parent = *queue.front();
        queue.pop();

        std::cout << parent->value << " ";

        if (parent->left) queue.push(&parent->left);
        if (parent->right) queue.push(&parent->right);
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        int u, v;
        char x;

        std::unique_ptr<Node> binary_tree;

        for (int i = 1; i <= n; ++i) {
            std::cin >> u >> v >> x;
            insert(binary_tree, u, v, x);
        }

        level_order(binary_tree);
        std::cout << "\n";

    }
}