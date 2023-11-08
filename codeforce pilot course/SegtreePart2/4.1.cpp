// тут можно написать обертку оберток для op_mod и op_calc, но ввиду того что проще сделать все присвоением, я не вижу смысла страдать ради этого, все проще
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;


typedef long long ll;
typedef tuple<ll, ll, bool, int> t;

class Segtree{
    public:
        Segtree(int n) {
            init(n);
        }

        void modify(int l, int r, int v, int type) {
            modify(l, r, v, 0, 0, size, type);
        }

        ll calc(int l, int r) {
            return calc(l, r, 0, 0, size);
        }

    private:
        vector<t> a;
        int size;

        void init(int n) {
            size = 1;
            while (size < n) size *= 2;
            a.assign(2 * size - 1, t(0, 0, false, 0));
        }

        ll op_modify_one(ll v) {
            return v;
        }

        ll op_modify_two(ll a, ll v) {
            return a + v;
        }

        ll op_calc(ll a, ll b) {
            return a + b;
        }

        void propagate(int x, int lx, int rx) {
           if (get<2>(a[x]) == false or (rx == lx + 1)) return;

           int half = (rx - lx) / 2;

            // присваивание
           if (get<3>(a[x]) == 1) {
                get<1>(a[2 * x + 1]) = op_modify_one(get<1>(a[x]));
                get<1>(a[2 * x + 2]) = op_modify_one(get<1>(a[x]));

                get<0>(a[2 * x + 1]) = op_modify_one(get<1>(a[x]) * half);
                get<0>(a[2 * x + 2]) = op_modify_one(get<1>(a[x]) * half);

                get<1>(a[x]) = 0;
                get<2>(a[x]) = false;
                get<3>(a[x]) = 0;
                
                get<2>(a[2 * x + 1]) = true;
                get<2>(a[2 * x + 2]) = true;

                get<3>(a[2 * x + 1]) = 1;
                get<3>(a[2 * x + 2]) = 1;
            } else {
                // прибавление
                if (get<2>(a[2 * x + 1]) and get<3>(a[2 * x + 1]) == 2)
                    get<1>(a[2 * x + 1]) = op_modify_two(get<1>(a[2 * x + 1]), get<1>(a[x]));
                else 
                    get<1>(a[2 * x + 1]) = op_modify_one(get<1>(a[x]));

                if (get<2>(a[2 * x + 2]) and get<3>(a[2 * x + 2]) == 2)
                    get<1>(a[2 * x + 2]) = op_modify_two(get<1>(a[2 * x + 2]), get<1>(a[x]));
                else 
                    get<1>(a[2 * x + 2]) = op_modify_one(get<1>(a[x]));

                get<0>(a[2 * x + 1]) = op_modify_two(get<0>(a[2 * x + 1]), get<1>(a[x]) * half);
                get<0>(a[2 * x + 2]) = op_modify_two(get<0>(a[2 * x + 2]), get<1>(a[x]) * half);
                
                get<1>(a[x]) = 0;
                get<2>(a[x]) = false;
                get<3>(a[x]) = 0;

                get<2>(a[2 * x + 1]) = true;
                get<2>(a[2 * x + 2]) = true;

                get<3>(a[2 * x + 1]) = 2;
                get<3>(a[2 * x + 2]) = 2;
            }
        }

        void modify(int l, int r, ll v, int x, int lx, int rx, int type) {
            propagate(x, lx, rx);
            if (rx <= l or lx >= r) return;
            if (lx >= l and rx <= r) {
                if (type == 1) {
                    get<0>(a[x]) = op_modify_one(v * (rx - lx));
                    get<1>(a[x]) = op_modify_one(v);
                    get<2>(a[x]) = true;
                    get<3>(a[x]) = 1;
                } else {
                    get<0>(a[x]) = op_modify_two(get<0>(a[x]), v * (rx - lx));
                    if (get<2>(a[x]) and get<3>(a[x]) == 2) 
                        get<1>(a[x]) = op_modify_two(get<1>(a[x]), v);
                    else {
                        get<1>(a[x]) = op_modify_one(v);
                    }
                    get<2>(a[x]) = true;
                    get<3>(a[x]) = 2;
                }
                return;
            }

            int m = (lx + rx) / 2;
            modify(l, r, v, 2 * x + 1, lx, m, type);
            modify(l, r, v, 2 * x + 2, m, rx, type);

            get<0>(a[x]) = op_calc(get<0>(a[2 * x + 1]), get<0>(a[2 * x + 2]));
        }

        ll calc(int l, int r, int x, int lx, int rx) {
            propagate(x, lx, rx);
            if (rx <= l or lx >= r) return 0;
            if (lx >= l and rx <= r) return get<0>(a[x]);

            int m = (lx + rx) / 2;  
            
            ll left = calc(l, r, 2 * x + 1, lx, m);
            ll right = calc(l, r, 2 * x + 2, m, rx);

            if (!get<2>(a[x])) return op_calc(left, right);
            else {
                if (get<3>(a[x]) == 1) 
                    return op_modify_one(get<1>(a[x]) * (min(r, rx) - max(l, lx)));
                else 
                    return op_modify_two(op_calc(left, right), get<1>(a[x]) * (min(r, rx) - max(l, lx)));
            }
        }

};

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    Segtree sg(n);
    while (m--) {
        int type;
        cin >> type;
        if (type == 1 or type == 2) {
            int l, r, v;
            cin >> l >> r >> v;
            sg.modify(l, r, v, type);
        } else {
            int l, r;
            cin >> l >> r;
            cout << sg.calc(l, r) << endl;
        }
    }
}