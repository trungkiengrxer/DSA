/*
Cho đồ thị có trọng số không âm G=<V, E> được biểu diễn dưới dạng danh sách cạnh trọng số. Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào hai ba số |V|, |E| tương ứng với số đỉnh và uÎV là đỉnh bắt đầu; |E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w tương ứng với một cạnh cùng với trọng số canh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra kết quả của mỗi test theo từng dòng. Kết quả mỗi test là trọng số đường đi ngắn nhất từ đỉnh u đến các đỉnh còn lại của đồ thị theo thứ tự tăng dần các đỉnh.
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const long long INF = 1e18;
long long n, m, start;
std::vector<long long> distance;
std::vector<std::vector<std::pair<long long, long long>>> adj;

void dijkstra(long long start) {
    distance[start] = 0;

    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<>> priority_queue;
    priority_queue.push({0, start});

    while (!priority_queue.empty()) {
        auto [d, u] = priority_queue.top();
        priority_queue.pop();

        if (d > distance[u]) continue;

        for (const auto &[v, w] : adj[u]) {
            if (distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                priority_queue.push({distance[v], v});
            }
        }
    }
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> m >> start;
        adj.assign(n + 1, std::vector<std::pair<long long, long long>>());
        distance.assign(n + 1, INF);

        for (long long i = 1; i <= m; ++i) {
            long long u, v, w;
            std::cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        dijkstra(start);

        for (long long u = 1; u <= n; ++u) {
            if (distance[u] == INF) {
                std::cout << -1 << " ";
                continue;
            }
            std::cout << distance[u] << " ";
        }
        std::cout << "\n";
    }
}