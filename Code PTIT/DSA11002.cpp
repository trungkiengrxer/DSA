#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

struct Node {
    std::string value;
    Node *left;
    Node *right;

    Node(std::string data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

typedef Node *TreeNode;

TreeNode build(std::vector<std::string> &s) {
    std::vector<TreeNode> tree;

    for (const auto &string : s) {
        tree.push_back(new Node(string));
    }

    for (int i = 0; i < s.size(); ++i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < s.size()) tree[i]->left = tree[l];
        if (r < s.size()) tree[i]->right = tree[r];
    }

    return tree[0];
}

int calculate(TreeNode root) {
    if (!root->left && !root->right) {
        return std::stoi(root->value);
    }

    int l = calculate(root->left);
    int r = calculate(root->right);

    if (root->value == "+") return l + r;
    if (root->value == "-") return l - r;
    if (root->value == "*") return l * r;
    if (root->value == "/") return l / r;
    return 0;
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
        std::cin.ignore();

        std::string line;
        std::getline(std::cin, line);

        std::string token;
        std::stringstream ss(line);
        std::vector<std::string> s;
        while (ss >> token) s.push_back(token);

        TreeNode tree = build(s);
        std::cout << calculate(tree) << "\n";
        delete_tree(tree);
    }
}