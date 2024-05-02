#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (auto i = (a); i >= (b); --i)
#define sz(x) (int)(x).size()
#define pb push_back
#define ppb pop_back
#define endl '\n'
#define fi first
#define se second

#ifdef Juhan404
#include "debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void run_case() {
    int n;
    cin >> n;

    vector<string> a(n + 1);
    ROF(i, n, 1) {
        cin >> a[i];
    }

    queue<int> q;

    FOR(i, 1, n) {
        if (a[i] == "+" || a[i] == "-" || a[i] == "*" || a[i] == "/") {
            int y = q.front();
            q.pop();

            int x = q.front();
            q.pop();

            if (a[i] == "+")
                q.push(x + y);
            if (a[i] == "-")
                q.push(x - y);
            if (a[i] == "*")
                q.push(x * y);
            if (a[i] == "/")
                q.push(x / y);
        }
        else
            q.push(stoi(a[i]));
    }
    cout << q.front() << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef Juhan404
    freopen("Error.txt", "w", stderr);
#endif

    int T = 1;
    cin >> T;

    for (int test = 1; test <= T; ++test) {

        run_case();
    }
    return 0;
}