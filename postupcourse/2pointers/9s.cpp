#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cmp(ll a, ll b)
{
  return a > b;
}

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  ll n, m;
  ll  s, a, b;
  cin >> n >> m >> s >> a >> b;
  vector<ll> ara(n);
  vector<ll> arb(m);

  for (ll i = 0; i < n; i++) cin >> ara[i];
  for (ll i = 0; i < m; i++) cin >> arb[i];

  sort(ara.begin(), ara.end(), cmp);
  sort(arb.begin(), arb.end(), cmp);

  for (ll i = 1; i < n; i++) ara[i] += ara[i - 1];
  for (ll i = 1; i < m; i++) arb[i] += arb[i - 1];

  ll cnta = min(s / a, n);
  ll cntb = min((s - cnta * a) / b, m);
  ll res = (cnta ? ara[cnta - 1] : 0) + (cntb ? arb[cntb - 1] : 0);
  
  while (cnta > 0)
  {
    while (min((s - cnta * a) / b, m) == cntb and cnta > 0) cnta --;
    cntb = min((s - cnta * a) / b, m);
    res = max(res, (cnta ? ara[cnta - 1] : 0) + (cntb ? arb[cntb - 1] : 0));
  }
  
  cout << res;
  return 0;
}