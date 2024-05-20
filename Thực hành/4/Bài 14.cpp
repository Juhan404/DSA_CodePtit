#include<bits/stdc++.h>

using namespace std;

vector<int> tree;
void in_order(int root, int n){
    if(root >= n)
        return;
    in_order(2 * root + 1, n);
    cout << tree[root] << " ";
    in_order(2 * root + 2, n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        tree.resize(n);
        for(int &x : tree){
            cin >> x;
        }
        in_order(0, n);
        cout << endl;
    }
    return 0;
}