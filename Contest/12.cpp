#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, x, y, z, result = 0, sum;
    std::cin >> n >> x >> y >> z;

    std::vector<std::pair<int, int>> arr(n);
    std::set<int> set;

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i].first >> arr[i].second;
        set.insert(arr[i].first);
        set.insert(arr[i].second);
    }

    for (const int &salary : set) {
        sum = 0;
        for (const auto &[a, b] : arr) {
            if (salary < a)
                sum += x;
            else if (salary > b)
                sum += z;
            else
                sum += y;
        }
        result = std::max(result, sum);
    }

    std::cout << result;
}