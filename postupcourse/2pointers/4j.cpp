#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  ll n, s;
  cin >> n >> s;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll l = 0;
  ll csum = 0;
  ll res = n + 1;
  for (ll r = 0; r < n; r++)
  {
    csum += a[r];
    while (csum - a[l] >= s) csum -= a[l], l++;
    if (csum >= s) res = min(res, r - l + 1);
  }

  if (res != n + 1) cout << res;
  else cout << -1;

  return 0;
}