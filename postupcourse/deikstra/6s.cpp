#include <bits/stdc++.h>

#define inf INT_MAX

using namespace std;

typedef long long ll;
typedef tuple<int, int, ll> tp;
typedef pair<int, int> pr;

bool ok(vector<vector<tp>>& graph, ll w)
{
    vector<int> dist(graph.size(), inf);
    dist[0] = 0;
    set<pr> heap;
    heap.insert(pr(0, 0));

    while (!heap.empty())
    {
        int x = heap.begin()->second;
        heap.erase(heap.begin());
        for (int i = 0; i < graph[x].size(); i++)
        {
            int to, time; ll w_max;
            tie(to, time, w_max) = graph[x][i];
            if (w > w_max) continue;
            if (dist[to] > dist[x] + time)
            {
                heap.erase(pr(dist[to], to));
                dist[to] = dist[x] + time;
                heap.insert(pr(dist[to], to));
            }
        }
    }

    return dist[graph.size() - 1] <= 1440 ? true : false;
}

int bin(vector<vector<tp>>& graph)
{
    int l = 0, r = (int)1e7 + 1;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (ok(graph, (ll)3e6 + (ll)mid * (ll)100)) l = mid;
        else r = mid;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<vector<tp>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int from, to, time; ll w_max;
        cin >> from >> to >> time >> w_max;
        from--, to--;
        graph[from].push_back(tp(to, time, w_max));
        graph[to].push_back(tp(from, time, w_max));
    }

    cout << bin(graph);

    return 0;
}