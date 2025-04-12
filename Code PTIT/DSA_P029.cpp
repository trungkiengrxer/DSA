/*
Trong kì nghỉ hè năm nay Tí được bố thưởng cho 1 tour du lịch quanh N đất nước tươi đẹp với nhiều thắng cảnh nổi tiếng. Tất nhiên Tí sẽ đi bằng máy bay.
Giá vé máy bay từ đất nước i đến đất nước j là C[i][j] (dĩ nhiên C[i][j] có thể khác C[j][i]). Tuy được bố thưởng cho nhiều tiền để đi du lịch nhưng Tí cũng muốn tìm cho mình 1 hành trình với chi phí rẻ nhất có thể để dành tiền mua quà về tặng mọi người.
Bạn hãy giúp Tí tìm 1 hành trình đi qua tất cả các nước, mỗi nước đúng 1 lần sao cho chi phí là bé nhất nhé.

Input:
Dòng đầu tiên là số lượng bộ test T (T <= 20).
Mỗi test bắt đầu bởi số nguyên dương N (5 <= N <= 15).
N dòng tiếp theo, mỗi dòng gồm N số nguyên mô tả chi phí C[i][j] (1<= C[i][j] <= 10000).

Output:
Với mỗi test, in ra đáp án tìm được trên một dòng.
*/

#include <iostream>
#include <vector>

void backtrack(std::vector<std::vector<int>> &c, std::vector<int> &temp, std::vector<bool> &visited, int &min_cost, int cost, int &n) {
    if (temp.size() == n) {
        int res = 0;
        // for (int i = 0; i < temp.size() - 1; ++i) {
        //     res += c[temp[i]][temp[i + 1]];
        // }

        // min_cost = std::min(min_cost, res);
 
    }

    if (cost >= min_cost) return;

    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;

        int last_pos = 0;
        if (!temp.empty()) last_pos = temp.back();

        temp.push_back(i);
        visited[i] = true;

        backtrack(c, temp, visited, min_cost, cost + c[last_pos][i], n);

        temp.pop_back();
        visited[i] = false;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, min_cost = 1e9;
        std::cin >> n;

        std::vector<int> temp;
        std::vector<bool> visited(n, false);
        std::vector<std::vector<int>> c(n, std::vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) std::cin >> c[i][j];
        }


        backtrack(c, temp, visited, min_cost, 0, n);

        std::cout << min_cost << "\n";
    }
}