#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

bool comparator(std::pair<int, int> a, std::pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i].first >> a[i].second;

    std::sort(a.begin(), a.end(), comparator);

    std::priority_queue<int, std::vector<int>, std::greater<>> queue;

    for (int i = 0; i < n; ++i) {
        if (queue.size() < a[i].first) queue.push(a[i].second);
    }
}