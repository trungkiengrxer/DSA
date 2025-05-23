#include <iostream>
#include <queue>
#include <sstream>
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

    ~Node() {
        delete left;
        delete right;
    }
};

using TreeNode = Node *;

std::string s;
std::vector<std::string> a;

TreeNode build() {
    if (a.empty() || a[0] == "N") return nullptr;
    TreeNode root = new Node(a[0]);
    std::queue<TreeNode> q;
    q.push(root);

    int index = 1;
    while (!q.empty() && index < a.size()) {
        TreeNode current = q.front();
        q.pop();
        if (index < a.size() && a[index] != "N") {
            current->left = new Node(a[index]);
            q.push(current->left);
        }
        ++index;
        if (index < a.size() && a[index] != "N") {
            current->right = new Node(a[index]);
            q.push(current->right);
        }
        ++index;
    }
    return root;
}

void rnl(TreeNode root) {
    if (!root) return;

    rnl(root->right);
    std::cout << root->value << " ";
    rnl(root->left);
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();

    while (t--) {
        std::getline(std::cin, s);

        a.clear();
        std::stringstream ss(s);
        std::string c;

        while (ss >> c) {
            a.push_back(c);
        }

        TreeNode binary_tree = build();

        rnl(binary_tree);
        std::cout << "\n";

        delete binary_tree;
    }
}