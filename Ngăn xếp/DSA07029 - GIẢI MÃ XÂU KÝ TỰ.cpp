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

void run_case() {
    string s;
    cin >> s;

    stack<string> st;

    FOR(i, 0, sz(s) - 1) {
        string temp = "";

        if (isdigit(s[i])) {
            while (i < sz(s) and isdigit(s[i])) { // lấy số lần lặp
                temp += s[i];
                i++;
            }
            --i;

            st.push(temp);
        }
        else if (s[i] == ']') {
            while (sz(st) && st.top()[0] != '[') { // lấy chữ trong ngoặc gần nhất
                temp = st.top() + temp;
                st.pop();
            }
            st.pop();

            int n = stoi(st.top()); // lấy số lần lặp
            st.pop();

            string a = "";

            while (sz(st) && isalpha(st.top()[0])) { // lấy xâu trước đó
                a = st.top() + a;
                st.pop();
            }

            string temp2 = "";
            while (n--) // lặp xâu trong ngoặc
                temp2 += temp;

            st.push(a + temp2);
        }
        else {
            if (s[i] == '[' && !isdigit(s[i - 1])) // nếu trước đó k có số lần lặp thì thêm 1
                st.push("1");

            st.push(string(1, s[i]));
        }
    }

    cout << st.top() << endl;
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