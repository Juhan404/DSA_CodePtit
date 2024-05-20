#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int par[N], sz[N];

int Find(int u) {
    return (par[u] == u) ? u : par[u] = Find(par[u]);
}

void Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x != y) {
        if (sz[x] < sz[y])
            swap(x, y);

        par[y] = x;
        sz[x] += sz[y];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (par[x] == 0)
            par[x] = x, sz[x] = 1;

        if (par[y] == 0)
            par[y] = y, sz[y] = 1;

        if (z == 1)
            Union(x, y);
        else
            cout << (Find(x) == Find(y) ? 1 : 0) << endl;
    }
}