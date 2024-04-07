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

int n;
char a[105][105];
int vsv[105][105], vsm[105][105], v[105][105], m[105][105];
pii vua, ma;
int res = 1e9;

int dx1[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy1[] = {1, -1, 0, 0, 1, -1, -1, 1};

int dx2[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy2[] = {-1, -2, -2, -1, 1, 2, 2, 1};

void BFS_vua(int x, int y) {
    queue<pii> q;

    q.push({x, y});
    vsv[x][y] = 1;
    v[x][y] = 0;

    while (!q.empty()) {
        pii temp = q.front();
        q.pop();

        FOR(i, 0, 7) {
            int x1 = temp.fi + dx1[i];
            int y1 = temp.se + dy1[i];

            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n && !vsv[x1][y1]) {
                vsv[x1][y1] = 1;
                v[x1][y1] = v[temp.fi][temp.se] + 1;
                q.push({x1, y1});
            }
        }
    }
}

void BFS_ma(int x, int y) {
    queue<pii> q;

    q.push({x, y});
    vsm[x][y] = 1;
    m[x][y] = 0;

    while (!q.empty()) {
        pii temp = q.front();
        q.pop();

        if (v[temp.fi][temp.se] == m[temp.fi][temp.se]) {
            res = min(res, m[temp.fi][temp.se]);
            debug(temp.fi, temp.se);
        }

        FOR(i, 0, 7) {
            int x1 = temp.fi + dx2[i];
            int y1 = temp.se + dy2[i];

            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n && !vsm[x1][y1]) {
                vsm[x1][y1] = 1;
                m[x1][y1] = m[temp.fi][temp.se] + 1;
                q.push({x1, y1});
            }
        }
    }
}

void run_case() {
    cin >> n;
    char c;
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> c;

            v[i][j] = 1e9;
            m[i][j] = 1e9;

            if (c == '#') {
                vsv[i][j] = 1;
                vsm[i][j] = 1;
            }

            if (c == 'M')
                ma = {i, j};
            else if (c == 'T')
                vua = {i, j};
        }
    }

    BFS_vua(vua.fi, vua.se);
    BFS_ma(ma.fi, ma.se);

    if (res == 1e9)
        cout << "-1" << endl;
    else
        cout << res << endl;
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