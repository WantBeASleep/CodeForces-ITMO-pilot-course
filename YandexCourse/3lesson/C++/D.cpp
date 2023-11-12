#include <iostream>

#include <unordered_set>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    unordered_set<int> yes;
    unordered_set<int> no;

    // после ввода числа getline говна поест и нагнется
    string skipendl;
    getline(cin, skipendl);

    for (;;) {
        string str, status;
        getline(cin, str);
        if (str == "HELP") {
            break;
        }
        getline(cin, status);

        istringstream stream(str);
        int x;

        while (stream >> x) {
            if (status == "YES" and (x <= n)) yes.insert(x);
            else if (status == "NO" and (x <= n)) no.insert(x);
        }
    }

    for (auto& x : no) {
        if (yes.count(x)) yes.erase(x);
    }

    for (int i = 1; i != n + 1; ++i) {
        if (yes.count(i)) cout << i << " ";
    }

    cout << endl;

    return 0;
}