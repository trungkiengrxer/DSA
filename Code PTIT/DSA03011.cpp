/*
Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất. Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j].
Dữ liệu vào
Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test gồm 2 dòng. Dòng đầu tiên là số nguyên N (N ≤ 2*106).
Dòng tiếp theo gồm N số nguyên dương c[i] ( 1 ≤ A[i] ≤ 10^9).

Kết quả
In ra đáp án của bộ test trên từng dòng, theo modulo 10^9+7.
*/

#include <iostream>
#include <queue>

const long long MOD = 1e9 + 7;

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, min_cost = 0;
        std::cin >> n;

        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> priority_queue;

        while (n--) {
            long long x;
            std::cin >> x;
            priority_queue.push(x);
        }

        while (priority_queue.size() > 1) {
            long long first_num = priority_queue.top();
            priority_queue.pop();

            long long second_num = priority_queue.top();
            priority_queue.pop();

            long long sum = (first_num + second_num) % MOD;
            min_cost = (min_cost + sum) % MOD;

            priority_queue.push(sum);
        }

        std::cout << min_cost << "\n";
    }
}