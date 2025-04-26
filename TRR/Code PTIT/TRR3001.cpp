#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

int n, u;
std::vector<std::set<int>> adj;
std::vector<int> euler;
std::vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void remove(int u, int v) {
    adj[u].erase(v);
    adj[v].erase(u);
}

void find_euler(int start) {
    std::stack<int> stack;
    stack.push(start);

    while (!stack.empty()) {
        int u = stack.top();

        if (!adj[u].empty()) {
            int v = *adj[u].begin();
            stack.push(v);
            remove(u, v);
        } else {
            stack.pop();
            euler.push_back(u);
        }
    }
}

int main() {
    std::ifstream input("CT.INP");
    std::ofstream print("CT.OUT");

    int t;
    input >> t;

    if (t == 1)
        input >> n;
    else
        input >> n >> u;

    adj.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            input >> x;
            if (x && i < j) {
                adj[i].insert(j);
                adj[j].insert(i);
            }
        }
    }

    if (t == 1) {
        int start = 0;
        while (start <= n && adj[start].empty()) ++start;

        if (start == 0) {
            print << 1;
            return 0;
        }

        visited.assign(n + 1, false);
        dfs(start);

        for (int i = 1; i <= n; ++i) {
            if (!adj[i].empty() && !visited[i]) {
                print << 0;
                return 0;
            }
        }

        int odd_count = 0;
        for (int i = 1; i <= n; ++i) {
            if (adj[i].size() % 2 != 0) {
                ++odd_count;
            }
        }

        if (odd_count == 0)
            print << 1;
        else if (odd_count == 2)
            print << 2;
        else
            print << 0;
    } else {
        find_euler(u);
        std::reverse(euler.begin(), euler.end());

        for (const int &v : euler) {
            print << v << " ";
        }
    }
    return 0;
}