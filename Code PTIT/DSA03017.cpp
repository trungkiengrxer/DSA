/*
Cho xâu ký tự S. Ta gọi giá trị của xâu S là tổng bình phương số lần xuất hiện mỗi ký tự trong S. Hãy tìm giá trị nhỏ nhất của xâu S sau khi thực hiện K lần loại bỏ ký tự.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là số K; phần thứ hai là một xâu ký tự S được viết trên một dòng.
T, S, K thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000; 1≤K≤1000.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int k, result = 0;
        std::string s;
        std::vector<int> frequency;
        std::unordered_map<char, int> map;

        std::cin >> k;
        std::cin >> s;

        for (const char &c : s) ++map[c];

        for (const auto &[c, freq] : map) frequency.push_back(freq);

        while (k--) {
            std::sort(frequency.rbegin(), frequency.rend());
            --frequency[0];
        }

        for (const int &num : frequency) result += (num * num);

        std::cout << result << "\n";
    }
}