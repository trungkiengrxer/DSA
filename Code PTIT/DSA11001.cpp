#include <iostream>
#include <memory>
#include <stack>
#include <string>

struct Node {
    char value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(char data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

std::unique_ptr<Node> build(std::string &postfix) {
    std::stack<std::unique_ptr<Node>> stack;

    for (const char c : postfix) {
        if (isalnum(c)) {
            stack.push(std::make_unique<Node>(c));
            continue;
        }

        auto right = std::move(stack.top());
        stack.pop();
        auto left = std::move(stack.top());
        stack.pop();
        auto op = std::make_unique<Node>(c);
        op->left = std::move(left);
        op->right = std::move(right);
        stack.push(std::move(op));
    }

    return std::move(stack.top());
}

void print_inorder(std::unique_ptr<Node> &node) {
    if (!node) return;

    print_inorder(node->left);
    std::cout << node->value;
    print_inorder(node->right);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string postfix;
        std::cin >> postfix;

        std::unique_ptr<Node> tree = build(postfix);
        print_inorder(tree);
        std::cout << "\n";
    }
}