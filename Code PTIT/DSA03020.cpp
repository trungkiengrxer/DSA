/*
Cho một mảng S gồm 2×N ký tự, trong đó có N ký tự ‘[’ và N ký tự ‘]’. Xâu S được gọi là viết đúng nếu S có dạng S2[S1] trong đó S, S2 là các xâu viết đúng. Nhiệm vụ của bạn là tìm số các phép đổi chỗ ít nhất các ký tự kề nhau của xâu S viết sai để  S trở thành viết đúng. Ví dụ với xâu S =”[]][][” ta có số phép đổi chỗ kề nhau ít nhất là 2.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu S viết sai theo nguyên tắc kể trên.
T, S thòa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤100000.

Output:
Đưa kết quả trên một dòng.
*/

#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int count = 0, result = 0;
        std::string s;

        std::cin >> s;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[')
                ++count;
            else
                --count;

            if (count >= 0) continue;
            for (int j = i + 1; j < s.size(); ++j) {
                if (s[j] == '[') {
                    result += j - i;
                    std::swap(s[i], s[j]);
                    count = 1;
                    break;
                }
            }
        }

        std::cout << result << "\n";
    }
}