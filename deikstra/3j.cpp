#include <bits/stdc++.h>
using namespace std;

#define inf 2009000999

typedef pair<int, int> pr;


int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pr>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int from, to, len;
        cin >> from >> to >> len;
        graph[from].push_back(pr(len, to));
        graph[to].push_back(pr(len, from));
    }

    vector<int> dist(n, inf);
    set<pair<int, int>> heap;
    dist[s] = 0;
    heap.insert(pr(0, s));

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

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    
    return 0;
}