/*
Cho dãy số A[] gồm có N phần tử. Nhiệm vụ của bạn là hãy tìm một số có tần số xuất hiện nhiều nhất, yêu cầu lớn hơn N/2 lần xuất hiện trong dãy số.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm số nguyên N (1≤ N ≤ 100 000), số lượng phần tử trong dãy số ban đầu.
Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 1 000 000).

Output:
Với mỗi test in ra đáp án của bài toán trên một dòng. Nếu không tìm được đáp án, in ra “NO”.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, max_freq = 0, result;
        std::cin >> n;

        std::vector<int> a(n);
        std::unordered_map<int, int> map;

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            ++map[a[i]];
        }

        for (const auto &[num, freq] : map) {
            if (freq > max_freq) {
                max_freq = freq;
                result = num;
            }
        }

        if (max_freq > n / 2)
            std::cout << result << "\n";
        else
            std::cout << "NO\n";
    }
}