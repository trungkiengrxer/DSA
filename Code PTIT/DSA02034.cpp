/*
Nam có N thẻ bài, mỗi thẻ ghi một con số từ 1 tới N. Không có 2 thẻ nào ghi hai số trùng nhau. Nam muốn xếp thứ tự các thẻ bài sao cho không có hai con số nào liền kề nhau ở cạnh nhau.
Ví dụ với N = 4 thì cách xếp 3142 là hợp lệ nhưng cách xếp 1324 không hợp lệ.
Hãy giúp Nam liệt kê tất cả các cách xếp thỏa mãn theo thứ tự từ điển.

Input
• Dòng đầu ghi số bộ test T (không quá 10)
• Mỗi bộ test ghi số N (3 < N < 10)

Output
• Với mỗi bộ test, ghi ra tất cả các cách xếp thứ tự thỏa mãn, mỗi cách trên một dòng.
*/

#include <iostream>
#include <vector>

void backtrack(int n, std::vector<int> &a, std::vector<bool> &used) {
    if (a.size() == n) {
        for (int num : a) std::cout << num;
        std::cout << "\n";
    }

    for (int i = 1; i <= n; ++i) {
        if (used[i]) continue;
        if (!a.empty() && std::abs(i - a.back()) == 1) continue;

        used[i] = true;
        a.push_back(i);
        backtrack(n, a, used);
        a.pop_back();
        used[i] = false;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a;
        std::vector<bool> used(10, false);

        backtrack(n, a, used);
    }
}