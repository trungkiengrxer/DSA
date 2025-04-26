#include <iostream>

const double epsilon = 1e-9;
int main() {
    if (0.1 + 0.2 - 0.3 <= epsilon)
        std::cout << "Yes";
    else
        std::cout << "No";
}