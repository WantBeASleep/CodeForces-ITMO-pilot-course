#include <bits/stdc++.h>
 
using namespace std;
 
class segtree {
    public:
        vector<int> a;
        int size;
 
        void init(int n) {
            size = 1;
            while(size < n) size *= 2;
            a.assign(2 * size - 1, 0);
        }
 
        void empty() {
            a.assign(2 * size - 1, 0);
        }
 
        void set(int i, int v) {
            set(i, v, 0, 0, size);
        }
 
        int sum(int l, int r) {
            return sum(l, r, 0, 0, size);
        }
 
        void set(int i, int v, int x, int lx, int rx) {
            if (rx == lx + 1) {
                a[x] = v;
                return;
            }
            int m = (lx + rx) / 2;
            if (i < m) set(i, v, 2 * x + 1, lx, m);
            else set(i, v, 2 * x + 2, m, rx);
            a[x] = a[2 * x + 1] + a[2 * x + 2];
        }
 
        int sum(int l, int r, int x, int lx, int rx) {
            if (lx >= r or rx <= l) return 0;
            if (lx >= l and rx <= r) return a[x];
            int m = (lx + rx) / 2;
            int lsum = sum(l, r, 2 * x + 1, lx, m);
            int rsum = sum(l, r, 2 * x + 2, m, rx);
            return lsum + rsum;
        }
};
 
int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
 
    segtree sg;
    sg.init(2 * n);
    vector<int> data(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> data[i];
 
    vector<int> openpos(n, -1);
    vector<int> ans(n, 0);
 
 
    for (int i = 0; i < 2 * n; i++) {
        int idx = i, num = data[i];
 
        if (openpos[num - 1] == -1) {
            openpos[num - 1] = idx;
            sg.set(idx, 1);
        } else {
            ans[num - 1] += sg.sum(openpos[num - 1] + 1, idx);
            sg.set(openpos[num - 1], 0);
        }
    }
    
    reverse(data.begin(), data.end());
 
    sg.empty();
    openpos.assign(n, -1);
 
    for (int i = 0; i < 2 * n; i++) {
        int idx = i, num = data[i];
 
        if (openpos[num - 1] == -1) {
            openpos[num - 1] = idx;
            sg.set(idx, 1);
        } else {
            ans[num - 1] += sg.sum(openpos[num - 1] + 1, idx);
            sg.set(openpos[num - 1], 0);
        }
    }
 
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
 
    return 0;
}