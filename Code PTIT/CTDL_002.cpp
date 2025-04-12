#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

void backtrack(int start, int sum, int k, int n, std::vector<int> &a, std::vector<int> &current, std::vector<std::vector<int>> &result) {
    if (sum == k) {
        result.push_back(current);
        return;
    }

    if (sum > k || start == n) return;

    current.push_back(a[start]);
    backtrack(start + 1, sum + a[start], k, n, a, current, result);
    current.pop_back();

    backtrack(start + 1, sum, k, n, a, current, result);
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n), current;
    std::vector<std::vector<int>> result;
    result.reserve(n);

    for (int i = 0; i < n; ++i) std::cin >> a[i];

    backtrack(0, 0, k, n, a, current, result);
    std::sort(result.rbegin(), result.rend());

    for (auto &set : result) {
        for (const int &num : set) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    std::cout << result.size();
}