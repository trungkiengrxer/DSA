/*
Bạn được giao cho N công việc, công việc thứ i có thời gian bắt đầu là A[i] và kết thúc tại B[i]. Tại một thời điểm, bạn chỉ có thể làm một công việc.

Bạn hãy lựa chọn các công việc một cách tối ưu sao cho số công việc làm được là nhiều nhất.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm 1 số nguyên N ( 1 ≤ N ≤ 100 000).
N dòng tiếp theo, mỗi dòng gồm 2 số A[i] và B[i] (0 ≤ A[i] < B[i] ≤ 106).

Output: Với mỗi test, in ra đáp án trên một dòng.
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

        std::vector<std::pair<int, int>> pair(n);

        for (int i = 0; i < n; ++i) std::cin >> pair[i].first >> pair[i].second;

        std::sort(pair.begin(), pair.end(), comparator);

        int result = 1, last_end = pair[0].second;

        for (int i = 1; i < n; ++i) {
            if (pair[i].first < last_end) continue;
            ++result;
            last_end = pair[i].second;
        }

        std::cout << result << "\n";
    }
}