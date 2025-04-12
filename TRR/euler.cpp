#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

std::set<int> adj[1001];
std::vector<int> deg(1001);

void find_euler(int v) {
    std::stack<int> stack;
    std::vector<int> ec;

    stack.push(v);
    while (!stack.empty()) {
        int x = stack.top();
        if (adj[x].size() != 0) {
            int y = *adj[x].begin();
            stack.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        } else {
            stack.pop();
            ec.push_back(x);
        }
    }

    std::reverse(ec.begin(), ec.end());

    for (int x : ec) std::cout << x << " ";
}
int main() {
    int n, s, x;
    std::cin >> n >> s;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> x;
            if (x) {
                adj[i].insert(j);
                adj[j].insert(i);
                ++deg[i];
                ++deg[j];
            }
        }
    }

    find_euler(s);
}