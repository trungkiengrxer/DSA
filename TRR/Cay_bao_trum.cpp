#include <iostream>
#include <vector>
#include <queue>

void readGraph(int& n, int& s, std::vector<std::vector<int>>& g) {
    std::cin >> n;
    std::cin >> s;
    g.assign(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> g[i][j];
}

void dfs(int u, int n, const std::vector<std::vector<int>>& g,
         std::vector<bool>& vis, std::vector<std::pair<int,int>>& e) {
    for (int v = 1; v <= n; ++v)
        if (g[u][v] && !vis[v]) {
            vis[v] = true;
            e.emplace_back(u, v);
            dfs(v, n, g, vis, e);
        }
}

void buildDFSTree(int n, int s, const std::vector<std::vector<int>>& g,
                  std::vector<std::pair<int,int>>& e) {
    std::vector<bool> vis(n + 1, false);
    vis[s] = true;
    dfs(s, n, g, vis, e);
}

void buildBFSTree(int n, int s, const std::vector<std::vector<int>>& g,
                  std::vector<std::pair<int,int>>& e) {
    std::vector<bool> vis(n + 1, false);
    std::queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 1; v <= n; ++v)
            if (g[u][v] && !vis[v]) {
                vis[v] = true;
                e.emplace_back(u, v);
                q.push(v);
            }
    }
}

void printEdges(const std::vector<std::pair<int,int>>& e) {
    for (auto p : e) {
        int u = p.first, v = p.second;
        if (u > v) std::swap(u, v);
        std::cout << u << ' ' << v << '\n';
    }
    std::cout << '\n';
}

int main() {
    int n, s;
    std::vector<std::vector<int>> g;
    readGraph(n, s, g);

    std::vector<std::pair<int,int>> dfsE, bfsE;
    buildDFSTree(n, s, g, dfsE);
    buildBFSTree(n, s, g, bfsE);

    std::cout << "DFS tree\n";
    printEdges(dfsE);
    std::cout << "BFS tree\n";
    printEdges(bfsE);
    return 0;
}
