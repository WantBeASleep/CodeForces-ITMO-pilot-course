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

  vector<int> c(n + m);
  int i = 0, j = 0;
  while (i < a.size() or j < b.size())
  {
    if (j == b.size() or (i < a.size() and a[i] < b[j]))
    {
      c[i + j] = a[i];
      i++;
    } else
    {
      c[i + j] = b[j];
      j++;
    }
  }

  for (int x : c)
  {
    cout << x << " ";
  }
  return 0;
}