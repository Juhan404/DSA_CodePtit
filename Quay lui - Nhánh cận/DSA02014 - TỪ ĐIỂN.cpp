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

int k, n, m, vs[4][4];
map<string, int> dic;
vector<string> v;
string a[4][4];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void flood_fill(int i, int j, string s) {
    if (dic[s])
        v.pb(s);

    vs[i][j] = 1;

    FOR(k, 0, 7) {
        int x = i + dx[k];
        int y = j + dy[k];

        if (x >= 1 && x <= n && y >= 1 && y <= m && vs[x][y] == 0)
            flood_fill(x, y, s + a[x][y]);
    }

    vs[i][j] = 0;
}

void run_case() {
    cin >> k >> n >> m;

    dic.clear();
    v.clear();

    FOR(i, 1, k) {
        string s;
        cin >> s;

        dic[s] = 1;
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> a[i][j];
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            flood_fill(i, j, a[i][j]);
        }
    }

    if (sz(v) == 0)
        cout << -1;
    else {
        for (string s : v)
            cout << s << ' ';
    }
    cout << endl;
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