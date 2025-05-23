#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::vector<std::string> result;

    std::queue<std::pair<std::string, int>> queue;
    queue.push({"1", 0});
    queue.push({"2", 1});

    while (!queue.empty()) {
        auto [s, cnt2] = queue.front();
        queue.pop();
        if (cnt2 > s.size() / 2) result.push_back(s);

        if (result.size() > 1001) break;

        queue.push({s + "0", cnt2});
        queue.push({s + "1", cnt2});
        queue.push({s + "2", cnt2 + 1});
    }

    std::sort(result.begin(), result.end(), [](std::string a, std::string b) -> bool {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) std::cout << result[i] << " ";
        std::cout << "\n";
    }

    return 0;
}
