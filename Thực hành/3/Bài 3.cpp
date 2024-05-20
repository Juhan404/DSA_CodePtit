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

int n, x[25], m;
bool final;

void gen_next() {
    int i = n - 1;
    while (i >= 1 && x[i] >= x[i + 1])
        --i;

    if (i == 0) {
        final = true;
    }
    else {
        int j = n;
        while (j >= 1 && x[j] < x[i])
            --j;

        swap(x[i], x[j]);
        reverse(x + i + 1, x + n + 1);
    }
}

void run_case() {
    final = false;

    cin >> n >> m;

    FOR(i, 1, n) {
        x[i] = i;
    }

    int stt = 0;

    while (!final) {
        ++stt;

        if (stt % m == 0) {
            string s = "";

            FOR(i, 1, n) {
                s += to_string(x[i]) + " ";
            }
            s.ppb();

            cout << s << endl;
        }

        gen_next();
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