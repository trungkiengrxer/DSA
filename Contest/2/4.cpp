#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<long long>> combination(61, std::vector<long long>(61));

void calculate() {
    for (long long i = 0; i < 61; ++i) {
        combination[i][0] = combination[i][i] = 1;
        for (long long j = 1; j < i; ++j) {
            combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
        }
    }
}

long long count(long long a, long long b) { return combination[a + b][a]; }

int main() {
    calculate();
    long long a, b, k;
    std::cin >> a >> b >> k;

    std::string result = "";
    while (a > 0 && b > 0) {
        long long c = count(a - 1, b);
        if (k <= c) {
            result += "a";
            --a;
        } else {
            result += "b";
            k -= c;
            --b;
        }
    }

    result += std::string(a, 'a');
    result += std::string(b, 'b');
    std::cout << result;
}