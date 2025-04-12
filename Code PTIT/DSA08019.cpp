/*
Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.

Input:
Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
T dòng kế tiếp mỗi dòng ghi số N (1<N<15).

Output:
Dòng đầu tiên là số lượng số lộc phát tìm được. Dòng thứ hai in ra đáp án theo thứ tự giảm dần.
*/

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

bool comparator(std::string &s, std::string &t) {
    if (s.size() == t.size()) return s > t;
    return s.size() > t.size();
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        std::vector<std::string> result;
        std::queue<std::string> queue;

        queue.push("6");
        queue.push("8");

        while (true) {
            std::string num = queue.front();
            if (num.size() > n) break;
            result.push_back(num);

            queue.pop();
            queue.push(num + "6");
            queue.push(num + "8");
        }

        std::sort(result.begin(), result.end(), comparator);

        std::cout << result.size() << "\n";
        for (const std::string &num : result) std::cout << num << " ";
        std::cout << "\n";
    }
}