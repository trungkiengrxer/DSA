/*
Trong 8 chữ cái Tiếng Anh đầu tiên (ABCDEFGH) thì có 2 nguyên âm là ‘A’, ‘E’, còn lại là phụ âm.
Người ta muốn ghép các chữ cái bắt đầu từ chữ cái ‘A’ cho đến chữ cái c (‘D’ <= c <= ‘H’) sao cho mỗi chữ cái được sử dụng đúng một lần và xâu kết quả không có nguyên âm nào bị kẹp giữa bởi hai phụ âm.
Hãy liệt kê các xâu thỏa mãn theo thứ tự từ điển.

Input
Chỉ có một dòng ghi chữ cái c (đảm bảo từ ‘D’ đến ‘H’).

Output
Liệt kê các xâu thỏa mãn, mỗi xâu trên một dòng.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool is_vowel(char c) { return c == 'A' || c == 'E'; }

bool is_valid(std::string &s) {
    for (int i = 0; i < s.size() - 2; ++i) {
        if (!is_vowel(s[i]) && is_vowel(s[i + 1]) && !is_vowel(s[i + 2])) return false;
    }
    return true;
}

void backtrack(int n, char c, std::string &s, std::unordered_map<char, bool> &used) {
    if (s.size() == n) {
        if (is_valid(s)) std::cout << s << "\n";
        return;
    }

    for (int ch = 'A'; ch <= c; ++ch) {
        if (used[ch]) continue;
        used[ch] = true;
        s.push_back(ch);
        backtrack(n, c, s, used);
        s.pop_back();
        used[ch] = false;
    }
}

int main() {
    char c;
    std::cin >> c;

    std::string s = "";
    std::unordered_map<char, bool> used;

    for (char ch = 'A'; ch <= c; ++ch) used[ch] = false;
    backtrack((c - 'A' + 1), c, s, used);
}
