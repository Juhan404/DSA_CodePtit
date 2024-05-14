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

struct node {
    int data;
    node *left;
    node *right;
};

void add_node(node *root, int par, int data, char pos) {
    if (root == NULL)
        return;

    if (root->data == par) {
        if (pos == 'L') {
            root->left = new node();
            root->left->data = data;
        }
        else {
            root->right = new node();
            root->right->data = data;
        }
    }
    else {
        add_node(root->left, par, data, pos);
        add_node(root->right, par, data, pos);
    }
}

void level_order(node *root) {
    queue<node *> q;
    q.push(root);

    while (sz(q)) {
        node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

void run_case() {
    int n;
    cin >> n;

    node *root = new node();

    FOR(i, 1, n) {
        int par, data;
        char pos;
        cin >> par >> data >> pos;

        if (i == 1) {
            root->data = par;
        }
        add_node(root, par, data, pos);
    }

    level_order(root);
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