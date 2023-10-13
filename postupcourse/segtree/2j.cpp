#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



class Tree {
    public:
        void build(vector<ll>& a) {
            init(a.size());

            build(a, 0, 0, size);
        }

        void set(int i, ll v) {
            set(0, i, v, 0, size);
        }           

        ll ffunc(int l, int r) {
            return ffunc(0, 0, size, l, r);
        }
    
    private:
        vector<ll> tree;
        int size;

        void init(int n) {
            size = 1; 
            while (size < n) size *= 2;
            tree.assign(2 * size - 1, 1);
        }

        ll evklid(ll val1, ll val2) {
            while (val1 and val2) {
                if (val1 > val2) {
                    val1 %= val2;
                } else {
                    val2 %= val1;
                }
            }
            return val1 + val2;
        }

        void build(vector<ll>& a, int x, int lx, int rx) {
            if (rx - lx == 1) {
                if (lx < a.size()) tree[x] = a[lx];
            } else {
                int m = (lx + rx) / 2;
                build(a, 2 * x + 1, lx, m);
                build(a, 2 * x + 2, m, rx);
                tree[x] = evklid(tree[2 * x + 1], tree[2 * x + 2]);
            }
        }

        void set(int x, int i, ll v, int lx, int rx) {
            if (rx - lx == 1) {
                tree[x] = v;
                return;
            }
            int m = (lx + rx) / 2;
            if (m > i) set(2 * x + 1, i, v, lx, m);
            else set(2 * x + 2, i, v, m, rx);
            tree[x] = evklid(tree[2 * x + 1], tree[2 * x + 2]);
            return;
        }

        ll ffunc(int x, int lx, int rx, int l, int r) {
            if (lx >= r or rx <= l) return 0;
            if (lx >= l and rx <= r) return tree[x];
            int m = (lx + rx) / 2;
            ll ls = ffunc(2 * x + 1, lx, m, l, r);
            ll rs = ffunc(2 * x + 2, m, rx, l, r);
            return evklid(ls, rs);
        }
};

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    Tree segtree;
    segtree.build(a);
    cin >> m;
    vector<ll> ans;
    for (int i = 0; i < m; i++)
    {
        char type;
        cin >> type;
        if (type == 'u') {
            int idx; ll v;
            cin >> idx >> v;
            idx--;
            segtree.set(idx, v);
        } else {
            int l, r;
            cin >> l >> r;
            l--;// полуинтервал
            ans.push_back(segtree.ffunc(l, r));
        }
    }

    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}