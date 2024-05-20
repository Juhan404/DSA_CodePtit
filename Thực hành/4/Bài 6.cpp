#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> v;

void back_tracking(string s, int len){
    if(s.size() == len){
        v.push_back(stoll(s));
        return;
    }
    back_tracking(s + '6' , len);
    back_tracking(s + '8' , len);
}

int main(){
    for(int i = 1 ; i <= 13 ; ++i){
        back_tracking("", i);
    }
    int t;
    cin >> t;
    while(t--){
        int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string s = to_string(v[i]);
        reverse(s.begin(), s.end());
        cout << v[i] << s << ' ';
    }
    cout << endl;
    }
}