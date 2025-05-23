#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n;
        std::cin.ignore();

        std::string first_tree;
        std::getline(std::cin, first_tree);

        std::cin >> m;
        std::cin.ignore();
        
        std::string second_tree;
        std::getline(std::cin, second_tree);

        if (first_tree == second_tree) std::cout << "1\n";
        else std::cout << "0\n";
    }
}