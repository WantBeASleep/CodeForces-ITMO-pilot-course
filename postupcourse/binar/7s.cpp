#include <bits/stdc++.h>

using namespace std;

bool ok(vector<long long>& a, int k, long long cnt)
{
  long long totalCnt = 0;
  for (int i = 0; i < a.size(); i++) totalCnt += min(a[i], cnt);
  return totalCnt >= k * cnt;
}

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  int k, n;
  cin >> k >> n;
  vector<long long> a;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    a.push_back(num);
  }

  long long l = 0;
  long long r = (long long)(50 * 1e9 + 1);
  while (l + 1 < r)
  {
    long long mid = (l + r) / 2;
    if (ok(a, k, mid)) l = mid;
    else r = mid;
  }

  cout << l;
  return 0;
}