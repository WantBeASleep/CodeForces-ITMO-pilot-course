#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
  ios::sync_with_stdio(NULL);
 
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  
  double l = 0;
  double r = 1e8;
 
  for (int t = 0; t < 100; t++)
  {
    double m = (l + r) * .5;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
      s += (int)(a[i] / m);
    }
    if (s >= k)
    {
      l = m;
    } else 
    {
      r = m;
    }
  }
 
  cout << fixed << setprecision(9) << l;
 
  return 0;
}