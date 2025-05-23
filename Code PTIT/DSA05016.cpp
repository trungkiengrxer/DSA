#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

std::vector<long long> ugly_numbers;

void generate() {
    std::set<long long> set;
    std::queue<long long> queue;

    queue.push((long long)1);
    set.insert((long long)1);

    while (set.size() < 10001) {
        long long num = queue.front();
        queue.pop();

        for (long long x : {2, 3, 5}) {
            long long ugly = num * (long long)x;
            if (set.find(ugly) != set.end() || ugly < 0) continue;
            queue.push(ugly);
            set.insert(ugly);
        }
    }

    for (const long long num : set) ugly_numbers.push_back(num);
}

int main() {
    generate();

    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;
        std::cout << ugly_numbers[n - 1] << "\n";
    }
}