#include <bits/stdc++.h>

using namespace std;

bool ok(vector<long long>& a, long long k, long long max)
{
  long long j = 1; // номер отрезка
  long long sumj = 0;
  for (long long i = 0; i < a.size(); i++)
  {
    if (sumj + a[i] <= max) sumj += a[i];
    else 
    {
      if (a[i] > max) return false;
      j++;
      sumj = a[i];
    }
  }

  return j <= k;
}

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<long long> a;

  long long l = 0;
  long long r = 0;
  for (long long i = 0; i < n; i++)
  {
    long long num;
    cin >> num;
    if (l < num) l = num;
    r += num;
    a.push_back(num);
  }
  l--;
  
  while (l + 1 < r)
  {
    long long mid = (l + r) / 2;
    if (ok(a, k, mid)) r = mid;
    else l = mid;
  }

  cout << r;
  return 0;
}