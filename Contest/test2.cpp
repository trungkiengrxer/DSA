#include <iostream>
#include <vector>
#include <deque>

void solve(int n, int k, std::vector<int>& a) {
    std::deque<int> dequeue;
    std::vector<int> result;

    for (int i = 0; i < k; i++) {
        while (!dequeue.empty() && a[dequeue.back()] <= a[i]) {
            dequeue.pop_back();
        }
        dequeue.push_back(i);
    }
    result.push_back(a[dequeue.front()]);

    for (int i = k; i < n; i++) {
        while (!dequeue.empty() && dequeue.front() <= i - k) {
            dequeue.pop_front();
        }

        while (!dequeue.empty() && a[dequeue.back()] <= a[i]) {
            dequeue.pop_back();
        }

        dequeue.push_back(i); 
        result.push_back(a[dequeue.front()]); 
    }

    
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) std::cout << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        solve(n, k, a);
    }
    return 0;
}