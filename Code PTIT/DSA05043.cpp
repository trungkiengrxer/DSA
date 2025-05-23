#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;

        std::cin >> s;

        int result = 0, n = s.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 1; ++j) {
                int low = i;
                int high = i + j;

                while (low >= 0 && high < n && s[low] == s[high]) {
                    int current_len = high - low + 1;
                    result = std::max(current_len, result);
                    --low;
                    ++high;
                }
            }
        }

        std::cout << result << "\n";
    }
}
