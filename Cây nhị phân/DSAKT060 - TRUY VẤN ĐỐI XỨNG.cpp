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

string s;
int n;

bool check(int l, int r) {
    while (l < r) {
        if (s[l] != s[r])
            return false;

        l++, r--;
    }
    return true;
}

void run_case() {
    cin >> s >> n;
    FOR(i, 1, n) {
        char c;
        int l, r;
        cin >> c >> l >> r;

        if (c == 'q') {
            if (check(l - 1, r - 1))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else {
            s[l - 1] = char(r + '0');
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef Juhan404
    freopen("Error.txt", "w", stderr);
#endif

    int T = 1;

    for (int test = 1; test <= T; ++test) {

        run_case();
    }
    return 0;
}