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

        void see(int i) {
            see(i, 0, 0, size);
        }

        void see(int i, int x, int lx, int rx) {
            if (rx == lx + 1) {
                arr[x]++;
                return;
            }
            int m = (lx + rx) / 2;
            if (i < m)
                see(i, 2 * x + 1, lx, m);
            else 
                see(i, 2 * x + 2, m, rx);
            arr[x] = arr[2 * x + 1] + arr[2 * x + 2];
        }

        int rsum(int l) { 
            return rsum(l, 0, 0, size);
        }

        int rsum(int l, int x, int lx, int rx) {
            if (lx >= l)
                return arr[x];
            int m = (lx + rx) / 2;
            if (m <= l)
                return rsum(l, 2 * x + 2, m, rx);
            else 
                return rsum(l, 2 * x + 1, lx, m) + arr[2 * x + 2];
        }
};

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    segtree sg;
    sg.init(n);

    for (int i = 0; i < n; i++) {
        cout << sg.rsum(a[i] - 1) << " ";
        sg.see(a[i] - 1);
    }

    return 0;
}
