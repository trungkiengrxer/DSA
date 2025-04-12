/*
Cho dãy số A[] gồm có N phần tử và số nguyên K.

Với mỗi dãy con liên tiếp có độ dài bằng K (từ trái sang phải), bạn hãy in ra phần tử lớn nhất trong dãy con này.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm số nguyên N và K (1≤ N ≤ 100 000, 1 ≤ K ≤ N).
Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^9).

Output:
Với mỗi test, in ra trên một dòng N-K+1 số nguyên là đáp án tìm được.
*/

#include <iostream>
#include <set>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n);
        std::multiset<int> multiset;
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        for (int i = 0; i < k; ++i) multiset.insert(a[i]);
        std::cout << *multiset.rbegin() << " ";
        for (int i = k; i < n; ++i) {
            multiset.insert(a[i]);
            multiset.erase(multiset.find(a[i - k]));
            std::cout << *multiset.rbegin() << " ";
        }

        std::cout << "\n";
    }
}