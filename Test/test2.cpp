#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> dp(n + 1, 1e9);

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i >= j) dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
        }
    }

    cout << dp[n - 1] << endl;
    return 0;
}