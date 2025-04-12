/*
Cho dãy số A[] gồm có N phần tử nguyên dương. Phần tử thứ i được gọi là điểm cân bằng của dãy số nếu như tổng các số bên trái bằng tổng các số bên phải của nó.

Nhiệm vụ của bạn là điểm cân bằng đầu tiên của dãy A[] cho trước. Nếu không có đáp án, in ra -1.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm số nguyên N (1≤ N ≤ 100 000), số lượng phần tử trong dãy số ban đầu.
Dòng tiếp theo gồm N số nguyên A[i] (-1000 ≤ A[i] ≤ 1000).

Output: 
Với mỗi test, in ra trên một dòng vị trí của điểm cân bằng tìm được.
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, result = -1;
        std::cin >> n;

        std::vector<int> a(n), prefix(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            
            if (i == 0) {
                prefix[i] = a[i];
                continue;
            }
            prefix[i] = prefix[i - 1] + a[i];
        }

        // for (auto num : prefix) std::cout << num << " ";
        // std::cout << "\n";

        for (int i = 0; i < n - 1; ++i) {
            if (prefix[i] == prefix[n - 1] - prefix[i + 1]) {
                result = i + 2;
                break;
            }
        }

        std::cout << result << "\n";
    }
}