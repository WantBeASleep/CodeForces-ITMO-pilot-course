#include <bits/stdc++.h>

#define inf INT_MAX

using namespace std;

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int n, s, f;
    cin >> n >> s >> f;
    s--;
    f--;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> a(n);
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            if (a[j] == -1) a[j] = inf;
        }
        graph[i] = a;
    }

    vector<bool> used(n, false);
    vector<int> dist(n, inf), p(n);
    set<pair<int, int>> heap;
    used[s] = true;
    dist[s] = 0;
    p[s] = 0;
    heap.insert(pair<int, int>(0, s));

    while (!heap.empty())
    {
        int x = heap.begin()->second;
        heap.erase(heap.begin());
        used[x] = true;
        for (int i = 0; i < n; i++)
        {
            if (used[i] or graph[x][i] == inf) continue;
            if (dist[i] > dist[x] + graph[x][i])
            {
                heap.erase(pair<int, int>(dist[i], i));
                dist[i] = dist[x] + graph[x][i];
                p[i] = x;
                heap.insert(pair<int, int>(dist[i], i));
            }
        }
    }
    
    
    if (dist[f] == inf) cout << -1;
    else 
    {
        vector<int> ans;
        ans.push_back(f + 1);
        int i = f;
        while (i != s) ans.push_back(p[i] + 1), i = p[i];
        for (int j = ans.size() - 1; j >= 0; j--)
        {
            cout << ans[j] << " ";
        }
    }

    return 0;
}