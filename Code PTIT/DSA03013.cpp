/*
Cho xâu ký tự S bao gồm các ký tự và số D. Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt lại các ký tự trong S để tất cả các ký tự giống nhau đều có khoảng cách là D hay không? Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1.

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số D; dòng tiếp theo là xâu S.
• T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000; 1≤D≤100.

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
        int d, is_valid = 1;
        std::string s;

        std::cin >> d;
        std::cin >> s;

        int n = s.size();
        std::unordered_map<char, int> map;

        for (char c : s) ++map[c];

        for (const auto &[c, freq] : map) {
            int slot = (freq - 1) * d + 1;
            if (slot > n) {
                is_valid = -1;
                break;
            }
        }

        std::cout << is_valid << "\n";
    }
}