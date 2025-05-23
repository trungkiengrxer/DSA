#include <iostream>
#include <unordered_map>
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
};

typedef Node *TreeNode;

std::vector<int> inorder;
std::vector<int> preorder;
std::unordered_map<int, int> inordered_map;

TreeNode build(int left, int right, int &index) {
    if (left > right) return nullptr;

    int root_value = preorder[index++];
    TreeNode root = new Node(root_value);

    int inorder_index = inordered_map.at(root_value);

    root->left = build(left, inorder_index - 1, index);
    root->right = build(inorder_index + 1, right, index);

    return root;
}

void print_postorder(TreeNode root) {
    if (!root) return;
    print_postorder(root->left);
    print_postorder(root->right);
    std::cout << root->value << " ";
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

        inorder.resize(n);
        preorder.resize(n);
        inordered_map.clear();

        for (int i = 0; i < n; ++i) {
            std::cin >> inorder[i];
            inordered_map[inorder[i]] = i;
        }

        for (int i = 0; i < n; ++i) std::cin >> preorder[i];

        int index = 0;
        TreeNode tree = build(0, n - 1, index);

        print_postorder(tree);
        std::cout << "\n";

        delete_tree(tree);
    }
}
