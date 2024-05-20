#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        stack<int> st;
        int res[s.size()];
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    res[i] = 1;
                    res[st.top()] = 0;
                    st.pop();
                }
                else{
                    res[i] = -1;
                }
            }
        }
        while(!st.empty()){
            res[st.top()] = -1;
            st.pop();
        }
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(' || s[i] == ')') cout << res[i];
            else cout << s[i];
        }
        cout << endl;
    }
    return 0;
}