/*
Cho số tự nhiên K và xâu ký tự các chữ số S.  Nhiệm vụ của bạn là đưa ra số lớn nhất bằng cách thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S. Ví dụ K =3 và S = “1234567” ta được “7654321”.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số K; dòng tiếp theo là xâu ký tự S.
T, K, S thỏa mãn ràng buộc: 1≤T ≤100; 1≤K≤10; 1≤.lenght(S)≤7.

Output:
*/

#include <iostream>
#include <string>
#include <vector>

void backtrack(int position, int k, std::string &num, std::string &result) {
    if (num > result) {
        result = num;
        return;
    }

    if (k == 0) {
        if (num > result) {
            result = num;
        }
        return;
    }

    for (int i = 0; i < num.size(); ++i) {
        for (int j = position; j < num.size(); ++j) {
            if (num[i] > num[j]) continue;
            std::swap(num[i], num[j]);
            backtrack(j + 1, k - 1, num, result);
            std::swap(num[i], num[j]);
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int k;
        std::string num;
        std::string result;

        std::cin >> k >> num;

        result = num;
        backtrack(0, k, num, result);
        std::cout << result << "\n";
    }
}