#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> a;
    for (int i = 0; i < N; i++)
    {
        vector<int> b(N);
        for (int j = 0; j < N; j++)
        {
            cin >> b[j];
            if (i == j) b[j] = 0;
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

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}