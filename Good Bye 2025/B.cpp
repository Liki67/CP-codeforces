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

    int cnt=0;
    if(s[0] == 'u')cnt++;
    if(s[s.size()-1]=='u')cnt++;

    int i=1;
    while(i<s.size()-2){
        if(s[i]=='u' && s[i+1]=='u'){
            cnt++;
            i+=2;
        }else{
            i++;
        }
    }cout<<cnt<<endl;
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