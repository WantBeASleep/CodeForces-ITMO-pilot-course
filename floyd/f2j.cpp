#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector<vector<ll>> a;
    for (int i = 0; i < N; i++)
    {
        vector<ll> b(N);
        for (int j = 0; j < N; j++)
        {
            cin >> b[j];
            if (i == j) b[j] = 0;
            if (b[j] == -1) b[j] = INT_MAX;
        }
        a.push_back(b);
    }



    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {

                a[i][j] = min(a[i][k] + a[k][j], a[i][j]);
            }
        }
    }
    
    ll ans = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] != INT_MAX) ans = max(ans, a[i][j]);
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }
    
    cout << ans;
    return 0;
}