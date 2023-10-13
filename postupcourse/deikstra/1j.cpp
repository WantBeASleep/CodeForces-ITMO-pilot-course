#include <bits/stdc++.h>

#define inf 500

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
    vector<int> dist(n, inf);
    set<pair<int, int>> heap;
    used[s] = true;
    dist[s] = 0;
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
                heap.insert(pair<int, int>(dist[i], i));
            }
        }
    }
    
    dist[f] == inf ? cout << -1 : cout << dist[f];

    return 0;
}