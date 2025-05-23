#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<long long> result;

void backtrack(long long len, std::string current) {
    if (current.size() > len) return;

    if (current.size() > 0) {
        result.push_back(std::stoll(current));
    }

    for (std::string s : {"4", "7"}) {
        backtrack(len, current + s);
    }
}

int main() {
    result.clear();
    backtrack(10, "");
    std::sort(result.begin(), result.end());

    long long a, b, sum = 0;
    std::cin >> a >> b;

    long long current = a;

    while (current <= b) {
        auto it = std::lower_bound(result.begin(), result.end(), current);

        long long next = *it;

        long long end = std::min(next, b);

        sum += (end - current + 1) * next;
        current = next + 1;
    }

    std::cout << sum << "\n";
}