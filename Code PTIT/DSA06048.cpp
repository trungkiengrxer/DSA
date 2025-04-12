/*
Ban đầu dãy số A[] gồm N phần tử đã được sắp xếp tăng dần. Các phần tử của dãy A[] có thể giống nhau. Sau đó ta thực hiện quay vòng phải, mỗi lần lấy một ký tự ở cuối dãy đưa lên đầu dãy.
Cho trạng thái dãy số của A[] sau khi đã thực hiện quay vòng K lần. Hãy tìm K.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số M, N, K; dòng tiếp theo đưa vào N số của mảng A[]các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤10^7; 0≤ A[i]≤10^18.

Output:
Đưa ra số lần quay vòng K của mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, count = 0;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        std::vector<int> temp = a;
        std::sort(temp.begin(), temp.end());

        int i = n - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (a[i] != temp[j])
                ++count;
            else {
                --i;
                --j;
            }
            if (a[i] < temp[j]) --j;
        }

        std::cout << count << "\n";
    }
}