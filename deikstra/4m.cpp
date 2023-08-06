#include <bits/stdc++.h>
using namespace std;

#define inf 2009000999

typedef pair<int, int> pr;


int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    cin >> m;
    vector<vector<pr>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        from--, to--;
        graph[from].push_back(pr(price[from], to));
        graph[to].push_back(pr(price[to], from));
    }

    vector<int> dist(n, inf);
    set<pair<int, int>> heap;
    dist[0] = 0;
    heap.insert(pr(0, 0));

    while (!heap.empty())
    {
        int x = heap.begin()->second;
        heap.erase(heap.begin());
        for (int i = 0; i < graph[x].size(); i++)
        {
            int to = graph[x][i].second;
            int w = graph[x][i].first;
            if (dist[to] > dist[x] + w)
            {
                heap.erase(pr(dist[to], to));
                dist[to] = dist[x] + w;
                heap.insert(pr(dist[to], to));
            }
        }
    }

    dist[n - 1] == inf ? cout << -1 : cout << dist[n - 1];
    
    return 0;
}