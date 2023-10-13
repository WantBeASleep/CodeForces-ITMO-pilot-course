#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class segtree {
    public:
        vector<ll> arr;
        ll size;

        void init(ll n) {
            size = 1;
            while (size < n) size *= 2;
            arr.assign(2 * size - 1, 0);
        }

        void build(vector<ll>& a) {
            init(a.size());
            _build(a, 0, 0, size);
        }

        void _build(vector<ll>& a, ll x, ll lx, ll rx) {
            if (rx == lx + 1) {
                if (lx < a.size())
                    if (a[lx] == 0)
                        arr[x] = 1;
                    else 
                        arr[x] = 0;
                return;
            }
            ll m = (lx + rx) / 2;
            _build(a, 2 * x + 1, lx, m);
            _build(a, 2 * x + 2, m, rx);
            arr[x] = arr[2 * x + 1] + arr[2 * x + 2];
        }

        void set(ll i, ll v) {
            _set(i, v, 0, 0, size);
        }

        void _set(ll i, ll v, ll x, ll lx, ll rx) {
            if (rx == lx + 1) {
                if (v == 0)
                    arr[x] = 1;
                else 
                    arr[x] = 0;
                return;
            }
            ll m = (lx + rx) / 2;
            if (m > i) _set(i, v, 2 * x + 1, lx, m);
            else _set(i, v, 2 * x + 2, m, rx);
            arr[x] = arr[2 * x + 1] + arr[2 * x + 2];
        }

        ll zeroidx(ll i) {
            return _zeroidx(i, 0, 0, size);
        }

        ll _zeroidx(ll i, ll x, ll lx, ll rx) {
            if (i > arr[x])
                return -1;
            if (rx == lx + 1)
                return lx;
            ll m = (lx + rx) / 2;
            ll leftzer = arr[2 * x + 1];
            if (i > leftzer)
                return _zeroidx(i - leftzer, 2 * x + 2, m, rx);
            else 
                return _zeroidx(i, 2 * x + 1, lx, m);
        }
};

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    segtree sg;
    sg.build(a);
    ll m;
    cin >> m;
    vector<ll> ans;
    for (ll i = 0; i < m; i++) {
        char ch;
        cin >> ch;
        if (ch == 's') {
            ll idx;
            cin >> idx;
            ll anwr = sg.zeroidx(idx);
            if (anwr != -1)
                anwr++;
            ans.push_back(anwr);
        } else {
            ll i, v;
            cin >> i >> v;
            if (i > sg.size)
                continue;
            i--;
            sg.set(i, v);
        }
    }

    for (ll i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}