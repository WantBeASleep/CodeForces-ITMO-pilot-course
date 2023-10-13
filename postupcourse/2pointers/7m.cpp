#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class mystack
{
  public:
    vector<ll> a, smin, smax;

    void push(ll num)
    {
      a.push_back(num);
      smin.push_back(smin.empty() ? num : min(smin.back(), num));
      smax.push_back(smax.empty() ? num : max(smax.back(), num));
    }

    ll pop()
    {
      ll ret = a.back();
      a.pop_back();
      smin.pop_back();
      smax.pop_back();
      return ret;
    }

    bool empty()
    {
      return a.empty();
    }

    ll ssmin()
    {
      return smin.empty() ? LLONG_MAX : smin.back();
    }

    ll ssmax()
    {
      return smax.empty() ? LLONG_MIN : smax.back();
    }
};

mystack s1, s2;
ll k;

void add(ll num)
{
  s1.push(num);
}

void remove()
{
  if (s2.empty())
  {
    while (!s1.empty()) s2.push(s1.pop());
  }
  s2.pop();
}

bool good()
{
  return max(s1.ssmax(), s2.ssmax()) - min(s1.ssmin(), s2.ssmin()) <= k;
}

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);

  int n;
  
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll ans = 0;
  int l = 0;
  for (int r = 0; r < n; r++)
  {
    add(a[r]);
    while (!good())  remove(), l++;
    ans += r - l + 1;
  }

  cout << ans;
  return 0;
}