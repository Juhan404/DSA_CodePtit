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

int n, pos;
vector<int> inorder, preorder;
unordered_map<int, int> idx;

void run_case() {
    cin >> n;

    inorder.resize(n);
    preorder.resize(n);
    idx.clear();

    FOR(i, 0, n - 1) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }

    for (int &x : preorder)
        cin >> x;

    pos = 0;

    function<void(int, int)> DFS = [&](int l, int r) {
        if (l > r)
            return;

        int root = preorder[pos++];
        int m = idx[root];

        DFS(l, m - 1);
        DFS(m + 1, r);

        cout << root << " ";
    };

    DFS(0, n - 1);
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