#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return x * x + sqrt(x);
}
 
// int main() {
//     double c;
//     cin >> c;
//     double l = 0, r = c;
 
//     for (int it = 0; it <= 250; it++) {
//         double m = (l + r) / 2;
//         if (f(m) > c)
//             r = m;
//         else
//             l = m;
//     }
 
//     cout << fixed << setprecision(9) << l;
 
//     return 0;
// }

int main()
{
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  double c;
  cin >> c;

  long double l = 0;
  long double r = 1e10 + 1;

  for (int i = 0; i < 100; i++)
  {
    double mid = (l + r) * 0.5;
    if (mid * mid + sqrt(mid) >= c) r = mid;
    else l = mid;
  }

  cout << fixed << setprecision(9) << r;
  return 0;
}