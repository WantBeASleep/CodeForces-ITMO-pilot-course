#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  int j = 0;
  vector<int> res(m);
  for (int i = 0; i < m; i++)
  {
    while (j < a.size() and a[j] < b[i]) j++;
    res[i] = j;
  }

  for (int x : res)
  {
    cout << x << " ";
  }
  return 0;
}