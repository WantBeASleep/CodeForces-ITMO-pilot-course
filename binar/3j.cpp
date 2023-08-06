#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);

  int n, k;
  cin >> n >> k;

  int array[n];
  for (int i = 0; i < n; i++)
  {
    cin >> array[i];
  }
  int maxOfEls = array[n - 1];

  for (int i = 0; i < k; i++)
  {
    int num;
    cin >> num;
    if (num > maxOfEls)
    {
      cout << n + 1 << endl;
      continue;
    }

    int l = 0, r = n - 1;
    int ans = (l + r) / 2;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (array[mid] >= num)
      {
        r = mid - 1; 
        ans = mid;
      }
      else l = mid + 1;
    }

    cout << ans + 1 << endl;
  }
  return 0;
}