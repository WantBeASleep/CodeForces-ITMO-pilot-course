#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a;
    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++)
    {
        vector<int> b(N, INT_MAX);
        b[i] = 0;
        a.push_back(b);
    }

    for (int i = 0; i < M; i++)
    {
        int s, e, l;
        cin >> s >> e >> l;
        a[s - 1][e - 1] = l;
        a[e - 1][s - 1] = l;
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!(a[i][k] == INT_MAX or a[k][j] == INT_MAX))
                {
                    a[i][j] = min(a[i][k] + a[k][j], a[i][j]);
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans[i] = max(ans[i], a[i][j]);
        }
    }

    int ansr = INT_MAX;
    int ansrr = 0;
    for (int i = 0; i < N; i++)
    {
        if (ans[i] < ansr) ansr = ans[i], ansrr = i;
    }
    ansrr++;

    cout << ansrr;

    return 0;
}