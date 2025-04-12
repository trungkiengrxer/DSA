/*
Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.

Input:
Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
T dòng kế tiếp mỗi dòng ghi số N (1<N<15).

Output:
Dòng đầu tiên là số lượng số lộc phát tìm được. Dòng thứ hai in đáp án theo thứ tự tăng dần.
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        std::vector<long long> result;
        std::queue<std::string> queue;

        queue.push("6");
        queue.push("8");

        while (true) {
            std::string num = queue.front();
            if (num.size() > n) break;
            result.push_back(std::stoll(num));

            queue.pop();
            queue.push(num + "6");
            queue.push(num + "8");
        }

        std::cout << result.size() << "\n";
        for (const long long &num : result) std::cout << num << " ";
        std::cout << "\n";
    }
}