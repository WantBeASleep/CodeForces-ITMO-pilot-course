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
  ll res = 0;
  for (ll r = 0; r < n; r++)
  {
    csum += a[r];
    while (csum > s) csum -= a[l], l++;
    res += r - l + 1;
  }

  cout << res;

  return 0;
}