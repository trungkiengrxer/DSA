/*
Cho dãy số a[] có n phần tử, đánh số từ 1 đến n. Hãy sắp xếp các phần tử ở vị trí lẻ theo thứ tự tăng dần, các phần tử ở vị trí chẵn theo thứ tự giảm dần.

Input
Dòng đầu tiên ghi số n, không quá 105
Dòng thứ 2 ghi n số của dãy a[] (a ≤ a[i] ≤ 10^9)

Output
Ghi ra dãy số kết quả trên một dòng
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), odd, even;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (i % 2 == 0) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }

    std::sort(odd.begin(), odd.end());
    std::sort(even.rbegin(), even.rend());

    int j = 0, k = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) std::cout << odd[j++] << " ";
        else std::cout << even[k++] << " ";
    }
    std::cout << "\n";

}