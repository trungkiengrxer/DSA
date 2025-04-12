/*
Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất. Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j].

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào số lượng sợi dây N; dòng tiếp theo đưa vào N số A[i] là độ dài của các sợi dây; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤10^6; 0≤A[i]≤10^6.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <queue>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, result = 0;
        std::cin >> n;

        std::vector<long long> a(n);

        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> priority_queue(a.begin(), a.end());

        while (priority_queue.size() > 1) {
            long long cost1 = priority_queue.top();
            priority_queue.pop();

            long long cost2 = priority_queue.top();
            priority_queue.pop();

            long long cost = cost1 + cost2;
            result += cost;

            priority_queue.push(cost);
        }

        std::cout << result << "\n";
    }
}