#include <bits/stdc++.h>
using namespace std;

#define inf (int)1e6

typedef tuple<int, int, int> tp;
typedef pair<int, int> pr;


int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int n, d, v, m;
    cin >> n >> d >> v >> m;
    d--, v--;
    vector<vector<tp>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int from, t_from, to, t_to;
        cin >> from >> t_from >> to >> t_to;
        from--, to--;
        graph[from].push_back(tp(to, t_from, t_to));
    }

    vector<int> dist(n, inf);
    set<pr> heap;
    dist[d] = 0;
    heap.insert(pr(0, d));

    while (!heap.empty())
    {
        int x = heap.begin()->second;
        heap.erase(heap.begin());
        for (int i = 0; i < graph[x].size(); i++)
        {
            int to, t_end, t_start;
            tie(to, t_start, t_end) = graph[x][i];
            if (t_start < dist[x]) continue;

            if (dist[to] > t_end)
            {
                heap.erase(pr(dist[to], to));
                dist[to] = t_end;
                heap.insert(pr(dist[to], to));
            }
        }
    }

    dist[v] == inf ? cout << -1 : cout << dist[v];
    
    return 0;
}