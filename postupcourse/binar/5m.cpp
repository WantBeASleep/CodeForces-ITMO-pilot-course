#include <bits/stdc++.h>

using namespace std;

bool ok(int array[][3], int n, int m, int t)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    int z = array[i][0] * array[i][1] + array[i][2];
    cnt += (t / z) * array[i][1] + min((t % z) / array[i][0], array[i][1]);
  }

  if (cnt >= m) return true;
  else return false;
}

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  int m, n;
  cin >> m >> n;
  int array[n][3];
  for (int i = 0; i < n; i++) cin >> array[i][0] >> array[i][1] >> array[i][2];

  int l = -1;
  int r = 15000 * 200 + 1;

  while(r > l + 1)
  {
    int mid = (l + r) / 2;
    if (ok(array, n, m, mid)) r = mid;
    else l = mid;
  }

  cout << r << endl;

  int all_count = m;
  for (int i = 0; i < n; i++)
  {
    int cnt;
    int z = array[i][0] * array[i][1] + array[i][2];
    cnt = (r / z) * array[i][1] + min((r % z) / array[i][0], array[i][1]);
    if (all_count >= cnt)
    {
      cout << cnt << " ";
      all_count -= cnt;
    } else
    {
      cout << all_count << " ";
      all_count = 0;
    }
  }
  return 0;
}