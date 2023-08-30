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
        }
 
        void build(vector<int> a) {
            build(a, 0, 0, size);
        }
 
        void build(vector<int> &_a, int x, int lx, int rx) {
            if (rx == lx + 1) {
                if (lx < _a.size()) a[x] = _a[lx] * pow(-1, lx % 2);
                return;
            }
            int m = (lx + rx) / 2;
            build(_a, 2 * x + 1, lx, m);
            build(_a, 2 * x + 2, m, rx);
            a[x] = a[2 * x + 1] + a[2 * x + 2];
        }
 
        void set(int i, int v) {
            set(i, v, 0, 0, size);
        }
 
        void set(int i, int v, int x, int lx, int rx) {
            if (rx == lx + 1) {
                a[x] = v * pow(-1, lx % 2);
                return;
            }
            int m = (lx + rx) / 2;
            if (i < m) set(i, v, 2 * x + 1, lx, m);
            else set(i, v, 2 * x + 2, m, rx);
            a[x] = a[2 * x + 1] + a[2 * x + 2];
        }
 
        int get(int i) {
            return get(i, 0, 0, size);
        }
 
        int get(int i, int x, int lx, int rx) {
            if (rx == lx + 1) return a[x];
            int m = (lx + rx) / 2;
            if (i < m) return get(i, 2 * x + 1, lx, m);
            else return get(i, 2 * x + 2, m, rx);
        }
 
        int sum(int l, int r) {
            return sum(l, r, 0, 0, size);
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
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    segtree sg;
    sg.init(n);
    sg.build(d);
    int m;
    cin >> m;
 
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
 
        if (!type) {
            int i, v;
            cin >> i >> v;
            i--;
            sg.set(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            r++;
 
            int sm = sg.sum(l + 1, r);
            if (l % 2) sm *= -1;
            cout << abs(sg.get(l)) + sm << endl;
        }
    }
 
    return 0;
}