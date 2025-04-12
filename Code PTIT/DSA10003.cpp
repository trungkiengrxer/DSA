/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Sử dụng Disjoin Set, hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh,  số cạnh của đồ thị; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:
Đưa ra YES hoặc “NO” kết quả test theo từng dòng tương ứng với đồ thị tồn tại hoặc không tồn tại chu trình.
*/

#include <iostream>
#include <vector>

class DSU {
   private:
    std::vector<int> size, parent;

   public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return true;
        if (size[u] < size[v]) std::swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        return false;
    }
};

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, e;
        bool is_valid = false;

        std::cin >> n >> e;

        DSU dsu(n);

        for (int i = 0; i < e; ++i) {
            int u, v;
            std::cin >> u >> v;

            if (dsu.unite(u, v)) is_valid = true;
        }

        if (is_valid)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}