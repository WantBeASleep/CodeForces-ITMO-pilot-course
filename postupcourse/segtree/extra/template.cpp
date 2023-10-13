#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define _DEFAULT 0

template <class T, class V, class R>
class segtree {
    public:
        void build(vector<V>& input) {
            _build(input, 0, 0, size);
        }

        void set(int i, V v) {
            _set(i, v, 0, 0, size);
        }

        R task() {

        }

    private:
        vector<T> data;
        int size;

        T cnv(V val) {
            
        }

        T func(V val1, V val2) {

        }

        void init(int n) {
            int size = 1;
            while (size < n) size *= 2;
            data.assign(size, _DEFAULT);
        }

        void _build(vector<V>& input, int x, int lx, int rx) {
            if (rx - lx == 1) {
                data[x] = cnv(input[lx]);
                return;
            }
            int m = (lx + rx) / 2;
            _build(input, 2 * x + 1, lx, m);
            _build(input, 2 * x + 2, m, rx);
            data[x] = func(data[2 * x + 1], data[2 * x + 2]);
        }

        void _set(int i, V v, int x, int lx, int rx) {
            if (rx - lx == 1) {
                data[x] = cnv(v);
            }
            int m = (lx + rx) / 2;
            if (m > i) _set(i, v, 2 * x + 1, lx, m);
            else _set(i, v, 2 * x + 2, m, rx);
            data[x] = func(data[2 * x + 1], data[2 * x + 2]);
        }

        R _task() {

        }

};


int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);

    return 0;
}