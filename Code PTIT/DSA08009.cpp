#include <iostream>
#include <queue>
#include <unordered_map>

int s, e;

int bfs() {
    std::unordered_map<int, bool> visited;
    std::queue<std::pair<int, int>> queue;

    queue.push({s, 0});
    visited[s] = true;

    while (!queue.empty()) {
        auto [u, count] = queue.front();
        queue.pop();

        if (u == e) return count;

        int v1 = u - 1;
        if (v1 >= 0 && !visited[v1]) {
            queue.push({v1, count + 1});
            visited[v1] = true;
        }

        int v2 = u * 2;

        if (v2 <= e * 2 && !visited[v2]) {
            queue.push({v2, count + 1});
            visited[v2] = true;
        }
    }

    return 0;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> s >> e;
        std::cout << bfs() << "\n";
    }
}