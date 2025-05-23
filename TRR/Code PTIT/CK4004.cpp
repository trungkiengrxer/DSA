#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

const int INF = 10000;

struct Edge {
    int w, u;
    bool operator<(const Edge &other) const { return w > other.w; }
};

bool comparator(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    // std::ifstream input("CK.INP");
    // std::ofstream print("CK.OUT");

    int n, s;
    std::cin >> n >> s;
    std::priority_queue<Edge> priority_queue;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
    std::vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) std::cin >> a[i][j];
    }

    std::vector<int> parent(n + 1, -1);
    std::vector<int> min_cost(n + 1, INF);

    min_cost[s] = 0;
    priority_queue.push({0, s});

    int total_weight = 0;
    std::vector<std::pair<int, int>> mst;

    while (!priority_queue.empty()) {
        Edge top = priority_queue.top();
        priority_queue.pop();

        int u = top.u;
        if (visited[u]) continue;
        visited[u] = true;
        total_weight += top.w;

        if (parent[u] != -1) mst.push_back({parent[u], u});

        for (int v = 1; v <= n; ++v) {
            if (!visited[v] && a[u][v] < min_cost[v] && a[u][v] < INF) {
                min_cost[v] = a[u][v];
                parent[v] = u;
                priority_queue.push({a[u][v], v});
            }
        }
    }

    bool connected = true;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }

    if (!connected) {
        std::cout << 0;
        return 0;
    }

    std::cout << total_weight << "\n";
    std::sort(mst.begin(), mst.end(), comparator);
    for (const auto &[u, v] : mst) {
        std::cout << u << " " << v << "\n";
    }

    return 0;
}