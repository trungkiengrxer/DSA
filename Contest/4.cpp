#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

long double epsilon = 1e6;

bool comparator_1(std::pair<long long, long long> &a, std::pair<long long, long long> &b) { return a.first < b.first; }

bool comparator_2(std::pair<long long, long long> &a, std::pair<long long, long long> &b) { return a.second < b.second; }

int main() {
    long long n;
    std::cin >> n;

    std::vector<std::pair<long long, long long>> a(n);

    for (long long i = 0; i < n; ++i) std::cin >> a[i].first >> a[i].second;

    std::sort(a.begin(), a.end(), comparator_1);

    long long median_x, median_y;

    if (n % 2 == 1) {
        median_x = a[n / 2].first;
    } else {
        median_x = a[n / 2 - 1].first + a[n / 2].first;
    }

    int result_1 = 0;

    for (int i = 0; i < n; ++i) {
        result_1 += (std::abs(a[i].first - median_x));
    }

    std::sort(a.begin(), a.end(), comparator_2);

    if (n % 2 == 1) {
        median_y = a[n / 2].second;
    } else {
        median_y = a[n / 2 - 1].second + a[n / 2].second;
    }

    bool is_valid = true;

    long long min_median = median_x;

    if (median_x > median_y) {
        min_median = median_y;
        is_valid = false;
    }

    long long result = 0;

    if (is_valid) {
        for (long long i = 0; i < n; ++i) {
            result += (a[i].first - min_median);
        }
    }


    std::cout << result;
}