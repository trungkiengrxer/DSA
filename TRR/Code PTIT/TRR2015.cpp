#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

int n, count = 0;
bool connected = true;
std::vector<bool> visited;
std::stack<int> stack;
std::vector<std::vector<int>> a;
std::vector<std::vector<int>> reversed;
std::vector<std::vector<int>> undirected;

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (!visited[v] && a[u][v]) dfs(v);
    }
    stack.push(u);
}

void undirected_dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (!visited[v] && undirected[u][v]) undirected_dfs(v);
    }
}

void reversed_dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (!visited[v] && reversed[u][v]) reversed_dfs(v);
    }
}

int main() {
    std::ifstream input("TK.INP");
    std::ofstream print("TK.OUT");

    input >> n;

    visited.assign(n + 1, false);
    a.assign(n + 1, std::vector<int>(n + 1, 0));
    reversed.assign(n + 1, std::vector<int>(n + 1, 0));
    undirected.assign(n + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            input >> a[i][j];
            reversed[j][i] = a[i][j];
            undirected[i][j] = undirected[j][i] = a[i][j] | a[j][i];
        }
    }

    for (int u = 1; u <= n; ++u) {
        if (visited[u]) continue;
        dfs(u);
    }

    for (int u = 1; u <= n; ++u) {
        visited.assign(n + 1, false);
        undirected_dfs(u);
        std::cout << "\n";
        for (int v = 1; v <= n; ++v) {
            if (!visited[v]) {
                connected = false;
                break;
            }
        }
    }

    visited.assign(n + 1, false);

    while (!stack.empty()) {
        int u = stack.top();
        stack.pop();
        if (visited[u]) continue;
        reversed_dfs(u);
        ++count;
    }

    if (count == 1)
        print << 1;
    else {
        if (!connected)
            print << 0;
        else
            print << 2;
    }
}