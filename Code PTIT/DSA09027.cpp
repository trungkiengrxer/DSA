/*
Cho đồ thị vô hướng có N đỉnh và M cạnh. Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh x và y có tồn tại đường đi tới nhau hay không?

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 2 số nguyên N, M (1 ≤ N, M ≤ 1000).
M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
Dòng tiếp là số lượng truy vấn Q (1 ≤ Q ≤ 1000).
Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên x và y.

Output:  Với mỗi truy vấn, in ra “YES” nếu có đường đi từ x tới y, in ra “NO” nếu ngược lại.
*/

#include <iostream>
#include <vector>

class DSU {
   private:
    std::vector<int> parent, size;

   public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;
        if (size[u] < size[v]) std::swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
};

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m, q;
        std::cin >> n >> m;

        DSU dsu(n);

        while (m--) {
            int u, v;
            std::cin >> u >> v;
            dsu.unite(u, v);
        }

        std::cin >> q;

        while (q--) {
            int x, y;
            std::cin >> x >> y;

            if (dsu.find(x) == dsu.find(y))
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }
}