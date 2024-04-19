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

int n, m, a[505][505], x_st, y_st, x_en, y_en, check;
char c;

void flood_fill(int i, int j, string path, int change) {
    if (i < 1 || i > n || j < 1 || j > m || a[i][j] == 0 || change > 2 || check == 1)
        return;

    if (i == x_en && j == y_en) {
        check = 1;
        return;
    }

    a[i][j] = 0;

    flood_fill(i + 1, j, path + "D", change + (path.back() != 'D' && sz(path) > 1));
    flood_fill(i - 1, j, path + "U", change + (path.back() != 'U' && sz(path) > 1));
    flood_fill(i, j + 1, path + "R", change + (path.back() != 'R' && sz(path) > 1));
    flood_fill(i, j - 1, path + "L", change + (path.back() != 'L' && sz(path) > 1));
}

void run_case() {
    cin >> n >> m;
    check = 0;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> c;

            a[i][j] = 1;

            if (c == '*')
                a[i][j] = 0;

            if (c == 'S') {
                x_st = i;
                y_st = j;
            }
            else if (c == 'T') {
                x_en = i;
                y_en = j;
            }
        }
    }

    flood_fill(x_st, y_st, "", 0);

    cout << (check ? "YES" : "NO") << endl;
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