/*
Cho hai số nguyên dương S và D, trong đó S là tổng các chữ số và D là số các chữ số của một số. Nhiệm vụ của bạn là tìm số nhỏ nhất thỏa mãn S và D? Ví dụ với S = 9, D = 2 ta có số nhỏ nhất thỏa mãn S và D là 18.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ 2 số S và D được viết trên một dòng.
T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤ S,D≤1000.

Output:
Đưa ra kết quả mỗi test theo từng dòng. Nếu không có đáp án, in ra -1.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int s, d;
        std::cin >> s >> d;

        std::vector<int> num(d, 0);
        std::string result;

        if (9 * d < s) {
            std::cout << "-1\n";
            continue;
        }

        num[0] = 1;
        --s;

        for (int i = d - 1; i >= 0 && s > 0; --i) {
            int digit = std::min(s, 9 - num[i]);
            num[i] += digit;
            s -= digit;
        }

        if (s > 0) {
            std::cout << "-1\n";
            continue;
        }

        for (int i = 0; i < d; ++i) std::cout << num[i];

        std::cout << "\n";
    }
}