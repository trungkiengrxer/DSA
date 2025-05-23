#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int m, n;
std::vector<std::string> a, dict;
std::vector<std::vector<bool>> visited;
std::vector<bool> found;
std::vector<std::string> result;

int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

bool is_valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < n && !visited[i][j]; }

void dfs(int i, int j, std::string &s) {
    if (!is_valid(i, j)) return;

    char c = a[i][j];
    if (c == 'q') {
        s += "qu";
    } else
        s.push_back(c);

    auto it = std::lower_bound(dict.begin(), dict.end(), s);

    if (it == dict.end() || it->compare(0, s.size(), s) != 0) {
        if (c == 'q')
            s.resize(s.size() - 2);
        else
            s.pop_back();
        return;
    }

    if (*it == s) {
        int index = it - dict.begin();
        if (!found[index]) {
            found[index] = true;
            result.push_back(s);
        }
    }

    visited[i][j] = true;

    for (int k = 0; k < 8; ++k) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        dfs(new_i, new_j, s);
    }

    visited[i][j] = false;

    if (c == 'q')
        s.resize(s.size() - 2);
    else
        s.pop_back();
}

int main() {
    std::cin >> m;
    dict.resize(m);

    for (int i = 0; i < m; ++i) std::cin >> dict[i];

    std::sort(dict.begin(), dict.end());

    while (std::cin >> n) {
        if (n == 0) break;
        a.assign(n, "");
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        visited.assign(n, std::vector<bool>(n, false));
        found.assign(m, false);
        result.clear();

        std::string temp = "";

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) dfs(i, j, temp);
        }

        std::sort(result.begin(), result.end());

        for (const auto word : result) {
            std::cout << word << "\n";
        }
        std::cout << "-\n";
    }
}