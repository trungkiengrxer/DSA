/*
Cho mảng A[] gồm n phần tử, hãy đưa ra số nhỏ nhất và số nhỏ thứ hai của mảng. Nếu không có số nhỏ thứ hai, hãy đưa ra -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n là số phần tử của mảng A[]; dòng tiếp theo đưa vào n số A[i]; các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤10^7.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <set>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::set<int> set;

        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            set.insert(x);
        }

        if (set.size() == 1)
            std::cout << "-1\n";
        else {
            auto it = set.begin();
            std::cout << *it << " ";
            ++it;
            std::cout << *it << "\n";
        }
    }
}