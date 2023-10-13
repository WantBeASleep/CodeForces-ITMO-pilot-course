#include <bits/stdc++.h>
 
using namespace std;
 
class segtree {
    public:
        vector<int> a;
        int size;
 
        void init(int n) {
            size = 1;
            while (size < n) size *= 2;
            a.assign(2 * size - 1, 0);
            init(n, 0, 0, size);
        }
 
        void init(int len, int x, int lx, int rx) {
            if (rx == lx + 1) {
                if (lx < len) a[x] = 1;
                return;
            }
            int m = (lx + rx) / 2;
            init(len, 2 * x + 1, lx, m);
            init(len, 2 * x + 2, m, rx);
            a[x] = a[2 * x + 1] + a[2 * x + 2];
        }
 
        void zero(int i) {
            zero(i, 0, 0, size);
        }
 
        void zero(int i, int x, int lx, int rx) {
            if (rx == lx + 1) {
                a[x] = 0;
                return;
            }
            int m = (lx + rx) / 2;
            if (i < m) zero(i, 2 * x + 1, lx, m);
            else zero(i, 2 * x + 2, m, rx);
            a[x] = a[2 * x + 1] + a[2 * x + 2];
        }
 
        int find(int k) {
            return find(k, 0, 0, size);
        }
 
        int find(int k, int x, int lx, int rx) {
            if (rx == lx + 1) return lx;
            int m = (lx + rx) / 2;
            if (a[2 * x + 2] >= k) {
                return find(k, 2 * x + 2, m, rx);
            } else {
                return find(k - a[2 * x + 2], 2 * x + 1, lx, m);
            }
        }
 
};
 
int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    segtree sg;
    int n;
    cin >> n;
    sg.init(n);
    vector<int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];
 
    vector<int> arr;
    for (int i = ar.size() - 1; i >= 0; i--) {
        int ans = sg.find(ar[i] + 1) + 1;
        sg.zero(ans - 1);
        arr.push_back(ans);
    }
 
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << " ";
    
 
    return 0;
}