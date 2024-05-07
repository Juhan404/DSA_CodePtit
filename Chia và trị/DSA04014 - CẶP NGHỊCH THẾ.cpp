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

ll Merge(ll a[], ll l, ll m, ll r) {
    vector<ll> x(a + l, a + m + 1), y(a + m + 1, a + r + 1);

    ll i = 0, j = 0, inv = 0;

    while (i < sz(x) && j < sz(y)) {
        if (x[i] <= y[j]) {
            a[l++] = x[i++];
        }
        else {
            inv += sz(x) - i;
            a[l++] = y[j++];
        }
    }
    while (i < sz(x))
        a[l++] = x[i++];

    while (j < sz(y))
        a[l++] = y[j++];

    return inv;
}

ll Merge_sort(ll a[], ll l, ll r) {
    ll dem = 0;
    if (l < r) {
        ll m = l + (r - l) / 2;

        dem += Merge_sort(a, l, m);
        dem += Merge_sort(a, m + 1, r);

        dem += Merge(a, l, m, r);
    }
    return dem;
}

void run_case() {
    ll n;
    cin >> n;

    ll a[n];
    for (ll &x : a)
        cin >> x;

    cout << Merge_sort(a, 0, n - 1) << endl;
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