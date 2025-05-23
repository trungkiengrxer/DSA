#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long k, sum = 0;

        std::string s;
        std::unordered_map<char, long long> map;
        std::priority_queue<long long> priority_queue;

        std::cin >> k;
        std::cin >> s;

        for (char &c : s) {
            ++map[c];
        }

        for (const auto &[_, freq] : map) {
            priority_queue.push(freq);
        }

        while (!priority_queue.empty() && k > 0) {
            long long freq = priority_queue.top();
            priority_queue.pop();
            if (freq > 1) priority_queue.push(freq - 1);
            --k;
        }

        while (!priority_queue.empty()) {
            long long freq = priority_queue.top();
            priority_queue.pop();
            sum += freq * freq;
        }

        std::cout << sum << "\n";
    }
}