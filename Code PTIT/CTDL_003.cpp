#include <iostream>
#include <vector>

void backtrack(std::vector<int> &x, std::vector<int> &optimal_solution, std::vector<int> &a, std::vector<int> &c, int n, int w, int &optimal_value) {
    if (x.size() == n) {
        int weight = 0, value = 0;
        for (int i = 0; i < n; ++i) {
            weight += a[i] * x[i];
            value += c[i] * x[i];
            if (weight > w) return;
        }

        if (value > optimal_value) {
            optimal_value = value;
            optimal_solution = x;
        }

        return;
    }

    for (int i = 0; i <= 1; ++i) {
        x.push_back(i);
        backtrack(x, optimal_solution, a, c, n, w, optimal_value);
        x.pop_back();
    }
}

int main() {
    int n, w, optimal_value = -1e9;
    std::cin >> n >> w;

    std::vector<int> c(n), a(n), optimal_solution, x;

    for (int i = 0; i < n; ++i) std::cin >> c[i];
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    backtrack(x, optimal_solution, a, c, n, w, optimal_value);

    std::cout << optimal_value << "\n";
    for (int i = 0; i < n; ++i) std::cout << optimal_solution[i] << " ";
}