#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class Tree {
    public:
        vector<ll> tree;
        int size;

        void init(int n) {
            size = 1; 
            while (size < n) size *= 2;
            tree.assign(2 * size - 1, LONG_MAX);
        }

        void build(vector<ll>& a, int x, int lx, int rx) {
            if (rx - lx == 1) {
                if (lx < a.size()) tree[x] = a[lx];
            } else {
                int m = (lx + rx) / 2;
                build(a, 2 * x + 1, lx, m);
                build(a, 2 * x + 2, m, rx);
                tree[x] = ::min(tree[2 * x + 1], tree[2 * x + 2]);
            }
        }

        void build(vector<ll>& a) {
            init(a.size());
            build(a, 0, 0, size);
        }

        void set(int x, int i, ll v, int lx, int rx) {
            if (rx - lx == 1) {
                tree[x] = v;
                return;
            }
            int m = (lx + rx) / 2;
            if (m > i) set(2 * x + 1, i, v, lx, m);
            else set(2 * x + 2, i, v, m, rx);
            tree[x] = ::min(tree[2 * x + 1], tree[2 * x + 2]);
            return;
        }

        void set(int i, ll v) {
            set(0, i, v, 0, size);
        }

        ll min(int x, int lx, int rx, int l, int r) {
            if (lx >= r or rx <= l) return LONG_MAX;
            if (lx >= l and rx <= r) return tree[x];
            int m = (lx + rx) / 2;
            ll ls = min(2 * x + 1, lx, m, l, r);
            ll rs = min(2 * x + 2, m, rx, l, r);
            return ::min(ls, rs);
        }        

        ll min(int l, int r) {
            return min(0, 0, size, l, r);
        }
};

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    Tree segtree;
    segtree.build(a);
    for (int i = 0; i < m; i++)
    {
        int type;
        cin >> type;
        if (type == 1) {
            int idx; ll v;
            cin >> idx >> v;
            segtree.set(idx, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << segtree.min(l, r) << endl;
        }
    }
    return 0;
}