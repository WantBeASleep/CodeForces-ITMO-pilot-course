#include <bits/stdc++.h>

using namespace std;

int zfunc(string s, int n) {
    vector<int> z(s.length(), 0);
    int l = 0, r = 0;
    for (int i = n + 1; i < s.length(); i++) {
        if (i < r) z[i] = min(z[i - l], r - i);
        while (i + z[i] < s.length() and s[z[i]] == s[i + z[i]]) z[i]++;
        if (z[i] == n) return -1;
        if (i + z[i] == s.length()) return z[i];
        if (r < i + z[i]) {
            r = i + z[i];
            l = i;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int glbl;
    cin >> glbl;
    for (int gl = 0; gl < glbl; gl++) {
        string s, t;
        cin >> s >> t;

        int st = zfunc(s + "$" + t, s.length());
        if (st == -1) {
            cout << t << "\n";
            continue;
        }

        int ts = zfunc(t + "$" + s, t.length());
        if (ts == -1) {
            cout << s << "\n";
            continue;
        }

        if (st > ts) cout << t + s.substr(st) << "\n";
        else cout << s + t.substr(ts) << "\n";
    }
    return 0;
}