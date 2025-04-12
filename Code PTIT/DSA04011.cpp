/*
Cho hai xâu nhị phân biểu diễn hai số. Nhiệm vụ của bạn là đưa ra tích của hai số. Ví dụ với xâu S1=”1100” và S2=”1010” ta sẽ có kết quả là 120.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 hai xâu nhị phân S1, S2 được viết trên một dòng.
T, S1, S2 thỏa mãn ràng buộc: 1≤T≤100;  1≤ length(S1), length(S2)≤30.

Output:
Đưa ra tích của mỗi test theo từng dòng.
*/

#include <cmath>
#include <iostream>
#include <string>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        std::string num1, num2;
        long long a = 0, b = 0;

        std::cin >> num1 >> num2;

        for (long long i = 0; i < num1.size(); ++i) {
            long long digit = num1[i] - '0';
            a += (digit * std::pow(2, num1.size() - i - 1));
        }

        for (long long i = 0; i < num2.size(); ++i) {
            long long digit = num2[i] - '0';
            b += (digit * std::pow(2, num2.size() - i - 1));
        }

        std::cout << a * b << "\n";
    }
}