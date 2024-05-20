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

int n, x[25], k;
string s;
bool final;
set<string> se;

void gen_next() {
    int i = k;
    while (i >= 1 && x[i] == n - k + i)
        --i;

    if (i == 0) {
        final = true;
    }
    else {
        ++x[i];
        FOR(j, i + 1, k) {
            x[j] = x[j - 1] + 1;
        }
    }
}

void run_case() {
    se.clear();
    final = false;

    cin >> s >> k;
    n = sz(s);

    FOR(i, 1, k) {
        x[i] = i;
    }

    while (!final) {
        string temp = "";

        FOR(i, 1, k) {
            temp += char(s[x[i] - 1]);
        }
        se.insert(temp);

        gen_next();
    }

    for (string x : se)
        cout << x << endl;
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