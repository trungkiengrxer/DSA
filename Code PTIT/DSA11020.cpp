#include <iostream>
#include <vector>

bool is_binary_tree(std::vector<int> &nodes) {
    for (int i = 0; i < nodes.size() - 1; ++i) {
        if (nodes[i] > nodes[i + 1]) return false;
        if (nodes[i] == nodes[i + 1]) return false;
    }

    return true;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> nodes(n);
        for (int i = 0; i < n; ++i) std::cin >> nodes[i];

        if (is_binary_tree(nodes))
            std::cout << "1\n";
        else
            std::cout << "0\n";
    }
}