#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int N, S, T;
    cin >> N >> S >> T;
    S--;
    T--;
    vector<vector<ll>> a;
    for (int i = 0; i < N; i++)
    {
        vector<ll> b(N);
        for (int j = 0; j < N; j++)
        {
            cin >> b[j];
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
                if (!(a[i][k] == INT_MAX or a[k][j] == INT_MAX)) a[i][j] = min(a[i][k] + a[k][j], a[i][j]);
            }
        }
    }
    
    a[S][T] == INT_MAX ? cout << -1 : cout << a[S][T];
    return 0;
}