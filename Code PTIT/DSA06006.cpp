/*
Cho mảng A[] gồm n phần tử. Các phần tử của mảng A[] chỉ bao gồm các số 0, 1, 2. Hãy sắp xếp mảng A[] theo thứ tự tăng dần. Ví dụ với A[] = {0, 2, 1, 2, 0} ta kết quả A[] = {0, 0, 1, 2, 2}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng A[]; dòng tiếp theo là n số A [i] của mảng A []các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 0≤ A[i] ≤2; 1≤ n ≤10^6.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::vector<int> counting_array(3, 0);

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            ++counting_array[a[i]];
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 1; j <= counting_array[i]; ++j) std::cout << i << " ";
        }

        std::cout << "\n";
    }
}