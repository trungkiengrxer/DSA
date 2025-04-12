/*
Cho số nguyên N. Nhiệm vụ của bạn cần tìm số nguyên X nhỏ nhất là bội của N, và X chỉ chứa hai chữ số 0 và 9.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10000). Mỗi bộ test chứa số nguyên N trên một dòng (1 ≤ N ≤ 500).

Output:  Với mỗi test in ra đáp án tìm được trên một dòng.
*/

#include <iostream>
#include <queue>
#include <string>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        std::queue<std::string> queue;
        queue.push("9");

        while (true) {
            std::string num = queue.front();

            if (std::stoll(num) % n == 0) {
                std::cout << num << "\n";
                break;
            }

            queue.pop();
            queue.push(num + "0");
            queue.push(num + "9");
        }
    }
}