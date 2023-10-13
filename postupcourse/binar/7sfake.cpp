#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);

  int k, n;
  cin >> k >> n;
  vector<int> a; 
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  sort(a.begin(), a.end());

  int cnt = 0;

  while (a[n - k] != 1)
  {
    int diff = a[n - k] - 1;
    cnt += diff;
    for (int i = n - k; i < n; i++) a[i] -= diff;
    sort(a.begin(), a.end());
  }

  int remainder = n - k + 1;
  int i = 0;
  a[n - k] = 0;
  while (remainder >= (a[n - k + 1 + i] - a[n - k + 1 + i - 1]) * (i + 1) and i < k - 1)
  {
    int add = a[n - k + 1 + i] - a[n - k + 1 + i - 1];
    cnt += add;
    remainder -= add * (i + 1);
    i++;
  }

  // остался слишком большой или полностью поглощен единицами
  if (i == k - 1) cnt += remainder / k;
  else cnt += remainder / (i + 1);

  cout << cnt;
  return 0;
}