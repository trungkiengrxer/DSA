/*
Cho hệ gồm N hành động. Mỗi hành động được biểu diễn như một bộ đôi <Si, Fi> tương ứng với thời gian bắt đầu và thời gian kết thúc của mỗi hành động. Hãy tìm phương án thực hiện nhiều nhất các hành động được thực hiện bởi một máy hoặc một người sao cho hệ không xảy ra mâu thuẫn.

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số lượng hành động N; dòng tiếp theo đưa vào N số Si tương ứng với thời gian bắt đầu mỗi hành động; dòng cuối cùng đưa vào N số Fi tương ứng với thời gian kết thúc mỗi hành động; các số được viết cách nhau một vài khoảng trống.
• T, N, Si, Fi thỏa mãn ràng buộc: 1≤T≤100;  1≤N, Fi, Si≤1000.

Output:
• Đưa số lượng lớn nhất các hành động có thể được thực thi bởi một máy hoặc một người.
*/

#include <algorithm>
#include <iostream>
#include <vector>

bool comparator(std::pair<int, int> &a, std::pair<int, int> &b) { return a.second < b.second; }

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n), b(n);
        std::vector<std::pair<int, int>> pair;

        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];
        for (int i = 0; i < n; ++i) pair.push_back({a[i], b[i]});

        std::sort(pair.begin(), pair.end(), comparator);

        int count = 1, last_end = pair[0].second;

        for (int i = 1; i < n; ++i) {
            if (pair[i].first >= last_end) {
                ++count;
                last_end = pair[i].second;
            }
        }

        std::cout << count << "\n";
    }
}