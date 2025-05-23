/*
Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự.

Hãy tìm xâu con đối xứng dài nhất của S.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm một xâu S có độ dài không vượt quá 1000, chỉ gồm các kí tự thường.

Output: Với mỗi test, in ra đáp án tìm được.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;

        std::cin >> s;

        int result = 0, n = s.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 1; ++j) {
                int low = i;
                int high = i + j;

                while (low >= 0 && high < n && s[low] == s[high]) {
                    int current_len = high - low + 1;
                    result = std::max(result, current_len);
                    --low;
                    ++high;
                } 
            }
        }

        std::cout << result << "\n";
    }
}
