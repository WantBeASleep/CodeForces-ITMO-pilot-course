#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;

  int array[n];
  for (int i = 0; i < n; i++) cin >> array[i];

  int min = array[0], max = array[n-1];

  for (int i = 0; i < k; i++)
  {
    int num;
    cin >> num;
    if (num < min or num > max)
    {
      cout << "NO" << endl;
      continue;
    }

    bool find = false;
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (array[mid] == num)
      {
        cout << "YES" << endl;
        find = true;
        break;
      }
      if (array[mid] > num) r = mid - 1;
      else l = mid + 1;
    }
    if (!find) cout << "NO" << endl;
  }


  return 0;
}