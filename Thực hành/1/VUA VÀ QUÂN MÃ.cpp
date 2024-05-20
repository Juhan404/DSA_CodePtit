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

char c;
int n, res = 1e9;
int king_vs[105][105], knight_vs[105][105];
int king[105][105], knight[105][105];
pii king_pos, knight_pos;

int king_dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int king_dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

int knight_dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knight_dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

void BFS_king(int x, int y) {
    queue<pii> q;

    q.push({x, y});
    king_vs[x][y] = 1;
    king[x][y] = 0;

    while (!q.empty()) {
        pii temp = q.front();
        q.pop();

        FOR(i, 0, 7) {
            int x1 = temp.fi + king_dx[i];
            int y1 = temp.se + king_dy[i];

            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n && !king_vs[x1][y1]) {
                king_vs[x1][y1] = 1;
                king[x1][y1] = king[temp.fi][temp.se] + 1;
                q.push({x1, y1});
            }
        }
    }
}

void BFS_knight(int x, int y) {
    queue<pii> q;

    q.push({x, y});
    knight_vs[x][y] = 1;
    knight[x][y] = 0;

    while (!q.empty()) {
        pii temp = q.front();
        q.pop();

        if (king[temp.fi][temp.se] == knight[temp.fi][temp.se])
            res = min(res, king[temp.fi][temp.se]);

        FOR(i, 0, 7) {
            int x1 = temp.fi + knight_dx[i];
            int y1 = temp.se + knight_dy[i];

            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n && !knight_vs[x1][y1]) {
                knight_vs[x1][y1] = 1;
                knight[x1][y1] = knight[temp.fi][temp.se] + 1;
                q.push({x1, y1});
            }
        }
    }
}

void run_case() {
    cin >> n;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> c;

            king[i][j] = 1e9;
            knight[i][j] = 1e9;

            if (c == '#') {
                king_vs[i][j] = 1;
                knight_vs[i][j] = 1;
            }

            if (c == 'M')
                knight_pos = {i, j};
            else if (c == 'T')
                king_pos = {i, j};
        }
    }

    BFS_king(king_pos.fi, king_pos.se);
    BFS_knight(knight_pos.fi, knight_pos.se);

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