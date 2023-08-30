#include <bits/stdc++.h>

using namespace std;

class segtree {
    public:
        vector<int> arr;
        int size;

        void init(int n) {
            size = 1;
            while (size < n) size *= 2;
            arr.assign(2 * size - 1, 0);
        }

        void build(vector<int>& a) {
            init(a.size());
            _build(a, 0, 0, size);
        }

        void _build(vector<int>& a, int x, int lx, int rx) {
            if (rx == lx + 1) {
                if (lx < a.size())
                    arr[x] = a[lx];
                return;
            }
            int m = (lx + rx) / 2;
            _build(a, 2 * x + 1, lx, m);
            _build(a, 2 * x + 2, m, rx);
            arr[x] = ::max(arr[2 * x + 1], arr[2 * x + 2]);
        }

        void set(int i, int v) {
            _set(i, v, 0, 0, size);
        }

        void _set(int i, int v, int x, int lx, int rx) {
            if (rx == lx + 1) {
                arr[x] = v;
                return;
            }
            int m = (lx + rx) / 2;
            if (m > i) _set(i, v, 2 * x + 1, lx, m);
            else _set(i, v, 2 * x + 2, m, rx);
            arr[x] = ::max(arr[2 * x + 1], arr[2 * x + 2]);
        }

        int first_above(int v, int l) {
            return _first_above(v, l, 0, 0, size);
        }

        int _first_above(int v, int l, int x, int lx, int rx) {
            if (rx <= l)
                return -1;
            if (arr[x] < v) 
                return -1;
            if (rx == lx + 1)
                return lx;
            int m = (lx + rx) / 2;
            int left = _first_above(v, l, 2 * x + 1, lx, m);
            if (left != -1)
                return left;
            int right = _first_above(v, l, 2 * x + 2, m, rx);
            return right;
        }
};

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    segtree sg;
    sg.build(a);
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, v;
            cin >> i >> v;
            sg.set(i, v);
        } else {
            int x, l;
            cin >> x >> l;
            cout << sg.first_above(x, l) << endl;
        }
    }
    return 0;
}