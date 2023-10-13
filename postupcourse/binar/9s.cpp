#include <bits/stdc++.h>

using namespace std;

bool ok(long long n, long long k, long long x)
{
  long long cnt = 0;
  for (long long i = 0; i < n; i++)
  {
    if (x <= i + 1) cnt += 0;
    else if (x <= (i + 1) * n)
    {
      cnt += (x - (i + 1) + (i + 1) - 1) / (i + 1);
    } else 
    {
      cnt += n;
    }
  }

  return cnt < k;
}

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  long long n;
  long long k;
  cin >> n >> k;

  long long l = 0;
  long long r = n * n + 1;

  while (l + 1 < r)
  {
    long long mid = (l + r)/2;
    if (ok(n, k, mid)) l = mid;
    else r = mid;
  }
  
  cout << l;
  return 0;
}