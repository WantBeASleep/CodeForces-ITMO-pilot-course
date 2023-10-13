#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void add(char ch, ll &cnta, ll &cntb, ll &rude)
{
  if (ch == 'a') cnta++;
  if (ch == 'b') cntb++, rude += cnta;
}

bool good(ll rude, ll c)
{
  return rude <= c;
}

void sremove(char ch, ll &cnta, ll &cntb, ll& rude)
{
  if (ch == 'a') cnta--, rude -= cntb;
  if (ch == 'b') cntb--;
}

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  int n;
  ll c;
  string s;

  cin >> n >> c;
  cin >> s;

  ll l = 0;
  ll cnta = 0, cntb = 0;
  ll rude = 0;
  ll ans = 0;
  for (int r = 0; r < n; r++)
  {
    add(s[r], cnta, cntb, rude);
    while (!good(rude, c)) sremove(s[l], cnta, cntb, rude), l++;
    ans = max(ans, r - l + 1);
  }

  cout << ans;
  return 0;
}