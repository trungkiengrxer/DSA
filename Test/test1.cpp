#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    vector<string> res;

    queue<pair<string, int>> qe;
    qe.push({"1", 0});
    qe.push({"2", 1});

    while (!qe.empty()) {
        auto [s, cnt2] = qe.front();
        qe.pop();
        if (cnt2 > s.size() / 2) res.push_back(s);

        if (res.size() > 1000) break;

        qe.push({s + "0", cnt2});
        qe.push({s + "1", cnt2});
        qe.push({s + "2", cnt2 + 1});
    }

    sort(res.begin(), res.end(), [](string a, string b) -> bool {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });

    int tc;
    cin >> tc;
    while (tc--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

#include <iostream>

long long GCD(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long LCM(long long a, long long b) { return a * b / GCD(a, b); }

int main() {
    long long t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        long long result = 1;
        for (long long i = 1; i <= n; ++i) {
            result = LCM(result, i);
        }
        std::cout << result << std::endl;
    }
}