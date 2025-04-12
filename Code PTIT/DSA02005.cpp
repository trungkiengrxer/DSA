/*
Cho xâu ký tự S bao gồm các ký tự in hoa khác nhau. Hãy đưa ra tất cả các hoán vị của xâu ký tự S. Ví dụ S=”ABC” ta có kết quả {ABC ACB BAC BCA CAB CBA}.

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test là một xâu ký tự S được viết trên 1 dòng.
• T, S thỏa mãn ràng buộc: 1≤T≤10; 1≤length(S) ≤10;

Output:
• Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void backtrack(std::string &s, std::string temp, std::unordered_map<char, bool> &used) {
    if (temp.size() == s.size()) {
        std::cout << temp << " ";
    }

    for (const char &ch : s) {
        if (used[ch]) continue;
        used[ch] = true;
        backtrack(s, temp + ch, used);
        used[ch] = false;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        std::string temp;
        std::unordered_map<char, bool> used;

        for (auto ch : s) used[ch] = false;

        backtrack(s, temp, used);
        std::cout << "\n";
    }
}