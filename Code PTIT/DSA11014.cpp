#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void addNode(int n, Node*& root) {
    unordered_map<int, Node*> m;
    for (int i = 0; i < n; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (m.find(u) == m.end()) {
            root = new Node(u);
            m[u] = root;
        }
        Node* parent = m[u];
        Node* child = new Node(v);

        if (c == 'L')
            parent->left = child;
        else
            parent->right = child;
        m[v] = child;
    }
}

bool isLeaf(Node* root) { return root && !root->left && !root->right; }

int sumRight(Node* root) {
    if (!root) return 0;
    int res = 0;

    if (isLeaf(root->right)) res += root->right->data;
    res += sumRight(root->right);

    if (root->left && !isLeaf(root->left)) res += sumRight(root->left);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* root = nullptr;
        addNode(n, root);
        cout << sumRight(root) << "\n";
    }
    return 0;
}