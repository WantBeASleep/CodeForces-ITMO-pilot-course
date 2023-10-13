#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  long long n, m;
  cin >> n >> m;
  map<long long, long long> a;
  map<long long, long long> b;

  for (long long i = 0; i < n; i++)
  {
    long long nums;
    cin >> nums;

    if (a.count(nums)) a[nums]++;
    else a[nums] = 1;
  }

  for (long long i = 0; i < m; i++)
  {
    long long nums;
    cin >> nums;

    if (b.count(nums)) b[nums]++;
    else b[nums] = 1;
  }

  map<long long, long long>::iterator itera = a.begin();
  map<long long, long long>::iterator iterb = b.begin();

  long long cnt = 0;
  for (; itera != a.end(); ++itera)
  {
    while (iterb != b.end() and iterb->first < itera->first) iterb++;
    if (iterb != b.end() and iterb->first == itera->first) cnt += itera->second * iterb->second;
  }

  cout << cnt;
  return 0;
}