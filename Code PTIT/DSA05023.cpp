/*
Cho số nguyên dương N được biểu diễn như một xâu ký tự số. Nhiệm vụ của bạn là tìm tổng của tất cả các số tạo bởi các xâu con của N. Ví dụ N=”1234” ta có kết quả là 1670 = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤10^12.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>
#include <string>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long result = 0;
        std::string s;

        std::cin >> s;

        for (long long i = 0; i < s.size(); ++i) {
            std::string num = "";
            for (long long j = i; j < s.size(); ++j) {
                num.push_back(s[j]);
                result += std::stoll(num);
            }
        }

        std::cout << result << "\n";
    }
}