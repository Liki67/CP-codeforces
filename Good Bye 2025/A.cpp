#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;

void solve() {
    string s;
    cin>>s;

    stack<char>st;

    st.push(s[0]);
    for(int i=1;i<s.size();i++){
        if((st.top() == 'Y' && s[i] == 'N')||st.top() == 'N' && s[i] == 'Y'){
            st.pop();
            st.push('Y');
        }else if( st.top() == 'N' && s[i] == 'N'){
            continue;
        }else{
            st.push(s[i]);
        }
    }
    if( st.size() == 1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}