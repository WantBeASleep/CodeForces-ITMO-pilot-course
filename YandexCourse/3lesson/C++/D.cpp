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
    unordered_set<int> no;

    for (;;) {
        string str, status;
        getline(cin, str);
        if (str == "HELP") {
            break;
        }
        getline(cin, status);

        istringstream stream(str);
        int x;
        if (status == "NO") {
            while (stream >> x) {
                no.insert(x);
            }
        }
    }

    for (int i = 1; i != n + 1; ++i) {
        if (!no.count(i)) cout << i << " ";
    }

    cout << endl;

    return 0;
}