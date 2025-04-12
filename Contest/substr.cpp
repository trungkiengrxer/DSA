#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>

int min_substr(std::string s) {
    std::unordered_map<char, int> freq;
    for (int i = 0; i < s.size(); ++i) ++freq[s[i]];
    int count = freq.size();

    int min_len = s.size();
    int left = 0;
    int count_unique = 0;
    std::unordered_map<char, int> window;

    for (int right = 0; right < s.size(); ++right) {
        ++window[s[right]];
        if (window[s[right]] == 1) ++count_unique;

        while (count_unique == count) {
            min_len = std::min(min_len, right - left + 1);
            --window[s[left]];
            if (window[s[left]] == 0) --count_unique;
            ++left;
        }
    }
    
    return min_len;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        std::cout << min_substr(s) << std::endl;
    }
    return 0;
}
