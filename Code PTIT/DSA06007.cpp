/*
Cho mảng A[] gồm n phần tử. Hãy tìm dãy con liên tục của mảng A[R], .., A[L] sao cho khi sắp xếp lại dãy con ta nhận được một mảng được sắp xếp. Ví dụ với A[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60} ta chỉ cần sắp xếp lại dãy con từ A[4],.., A[9]: {30, 25, 40, 32, 31, 35} để có mảng được sắp.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng A[]; dòng tiếp theo là n số A [i] của mảng A []các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^6; 0≤ A[i] ≤10^7.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, start, end;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        std::vector<int> temp = a;
        std::sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) {
            if (temp[i] != a[i]) {
                start = i;
                ++start;
                break;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (temp[i] != a[i]) {
                end = i;
                ++end;
                break;
            }
        }

        std::cout << start << " " << end << "\n";
    }
}