/*
Cho xâu ký tự S bao gồm các ký tự in thường. Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt lại các ký tự trong S để hai ký tự giống nhau đều không kề nhau hay không? Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1.

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự S được viết trên một dòng.
• T, S thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000.

Output:
• Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        bool is_valid = true;
        std::string s;
        std::unordered_map<char, int> map;

        std::cin >> s;
        for (char c : s) ++map[c];

        for (auto &[c, freq] : map) {
            if (freq > (s.size() + 1) / 2) {
                is_valid = false;
                break;
            }
        }

        if (is_valid)
            std::cout << 1;
        else
            std::cout << -1;
        std::cout << "\n";
    }
}