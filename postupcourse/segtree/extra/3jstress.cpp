#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define _DEFAULT 0

template <class T, class V, class R>
class segtree {
    public:
        vector<T> data;
        int size;
        void build(vector<V>& input) {
            init(input.size());
            _build(input, 0, 0, size);
        }

        void set(int i, V v) {
            _set(i, v, 0, 0, size);
        }

        R task(V x, int l) {
            return _task(x, l, 0, 0, size);
        }

    private:
        

        T cnv(V val) {
            return val;
        }

        T func(V val1, V val2) {
            return ::max(val1, val2);
        }

        void init(int n) {
            size = 1;
            while (size < n) size *= 2;
            data.assign(2 * size - 1, _DEFAULT);
        }

        void _build(vector<V>& input, int x, int lx, int rx) {
            if (rx - lx == 1) {
                if (lx < input.size()) data[x] = cnv(input[lx]);
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
                return;
            }
            int m = (lx + rx) / 2;
            if (m > i) _set(i, v, 2 * x + 1, lx, m);
            else _set(i, v, 2 * x + 2, m, rx);
            data[x] = func(data[2 * x + 1], data[2 * x + 2]);
        }

        R _task(V x, int l, int i, int lx, int rx) {
            if (rx <= l) return -1;
            if (rx - lx == 1) {
                if (data[i] >= x) return i;
            }
            R left = -1, right = -1;
            int m = (lx + rx) / 2;
            if (data[2 * i + 1] >= x)
                left = _task(x, l, 2 * i + 1, lx, m);
            if (left != -1) return left;
            if (data[2 * i + 2] >= x)
                right = _task(x, l, 2 * i + 2, m, rx);
            return right;
        }

};

void stress_test_debug(vector<ll>& a, ll x, int l);

typedef pair<ll, int> pr;
void segtreefullprint(segtree<ll, ll, int>& sg) {
    queue<pr> que;
    que.push(pr(sg.data[0], 0));
    int lastLine = sg.size - 1;
    while(!que.empty()) {
        int len = que.size();
        for (int i = 0; i < len; i++) {
            ll val = que.front().first;
            int x = que.front().second;
            que.pop();
            cout << val << " ";
            if (x < lastLine) {
                que.push(pr(sg.data[2 * x + 1], 2 * x + 1));
                que.push(pr(sg.data[2 * x + 2], 2 * x + 2));
            }
        }
        cout << endl;
    }
}

int GetRandomNumber(int min, int max)
{
    // srand(time(NULL));
    int num = min + rand() % (max - min + 1);
    return num;
}

int search(vector<ll>& a, ll x, int l) {
    for (int i = l; i < a.size(); i++) {
        if (a[i] >= x) return i;
    }
    return -1;
}
#define MYRAND (ll)1e9
void stress_test() {
    int n = 100000;
    int pass = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) a[i] = GetRandomNumber(0, MYRAND);
    segtree<ll, ll, int> sg; sg.build(a);
    while(true) {
        if (!(pass % 100000)) {
            n = GetRandomNumber(0, 100000);
            a.assign(n, 0);
            for (int i = 0; i < n; i++) a[i] = GetRandomNumber(0, MYRAND);
            sg.build(a);
        }

        int type = GetRandomNumber(1, 2);
        if (type == 1) {
            int i = GetRandomNumber(0, n - 1);
            ll v = GetRandomNumber(0, MYRAND);
            a[i] = v;
            sg.set(i, v);
        } else {
            ll x = GetRandomNumber(0, MYRAND);
            int l = GetRandomNumber(0, n - 1);
            
            int arrayAns = search(a, x, l);
            int sgTreeAns = sg.task(x, l);
            if (sgTreeAns != -1) sgTreeAns -= sg.size - 1;

            if (arrayAns != sgTreeAns) {
                cout << "WOOOOOW" << endl;
                cout << "ARRAY: ";
                for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
                cout << endl;
                cout << "TREE: " << endl;
                segtreefullprint(sg);
                cout << "TASK: x: " << x << " l: " << l << endl;
                cout << "ARRAY ANSWR: " << arrayAns << endl;
                cout << "TREE ANSWR: " << sgTreeAns << endl;
                // stress_test_debug(a, x, l);
                return;
            }

            pass++;
            cout << "TASK: x: " << x << " l: " << l << " n: " << n << endl;
            cout << "Test №" << pass << " ok" << endl;

        }

    }
}

void stress_test_debug(vector<ll>& a, ll x, int l) {
    segtree<ll, ll, int> sg;
    sg.build(a);
    segtreefullprint(sg);
    sg.task(x, l);
}


int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    stress_test();
    // int n, m;
    // cin >> n >> m;
    // vector<ll> a(n);
    // for (int i = 0; i < n; i++) cin >> a[i];
    // segtree<ll, ll, int> sg;
    // sg.build(a);
    // segtreefullprint(sg);
    // for (int i = 0; i < m; i++) {
    //     int type;
    //     cin >> type;
    //     if (type == 1) {
    //         int i; ll v;
    //         cin >> i >> v;
    //         sg.set(i, v);
    //     } else {
    //         ll x; int l;
    //         cin >> x >> l;
    //         int idx =  sg.task(x, l);
    //         if (idx == -1 ) cout << -1 << endl;
    //         else {
    //             cout << idx - (sg.size - 1) << endl;
    //         }
    //     }
    // }

    return 0;
}
