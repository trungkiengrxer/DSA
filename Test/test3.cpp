#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void DFS(string s, int n, vector<string>& res) {
    if (s.size() == n) {
        res.push_back(s);
        return;
    }
    DFS(s + "0", n, res);
    DFS(s + "1", n, res);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<string> res;

        DFS("", n, res);
        for (int i = 0; i < res.size(); i++) {
            for (char c : res[i]) {
                if (c == '0')
                    cout << 'A';
                else
                    cout << 'B';
            }
            if (i != res.size() - 1) cout << ",";
        }
        cout << endl;
    }
    return 0;
}