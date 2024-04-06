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

int n, m, k, a[105][105];
vector<pair<pii, pii>> v; // vị trí rào chắn
vector<pii> sheep;        // vị trí cừu
int cmp_index = 0;        // số thành phần liên thông
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int cnt[105]; // số cừu trong mỗi thành phần liên thông
int res = 0;

bool check(pii x, pii y) { // kiểm tra xem có thể đi từ x đến y không
    if (y.fi < 1 || y.fi > n || y.se < 1 || y.se > n || a[y.fi][y.se] != 0)
        return false;

    for (auto i : v) { // kiểm tra xem có rào chắn nào nằm giữa x và y không
        if ((i.fi == x && i.se == y) || (i.fi == y && i.se == x))
            return false;
    }
    return true;
}

void flood_fill(int i, int j) {
    a[i][j] = cmp_index;

    FOR(k, 0, 3) {
        int x = i + dx[k];
        int y = j + dy[k];

        if (check({i, j}, {x, y}))
            flood_fill(x, y);
    }
}

void run_case() {
    cin >> n >> k >> m;

    v.resize(m);
    for (auto &i : v)
        cin >> i.fi.fi >> i.fi.se >> i.se.fi >> i.se.se;

    sheep.resize(k);
    for (auto &i : sheep)
        cin >> i.fi >> i.se;

    for (auto i : sheep) { // đánh dấu các thành phần liên thông
        if (a[i.fi][i.se] == 0) {
            cmp_index++;
            flood_fill(i.fi, i.se);
        }
    }

    for (auto i : sheep) // đếm số cừu trong mỗi thành phần liên thông
        cnt[a[i.fi][i.se]]++;

    FOR(i, 1, cmp_index) {
        int temp = 0;
        FOR(j, i + 1, cmp_index) {
            temp += cnt[j];
        }
        res += cnt[i] * temp;
    }

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