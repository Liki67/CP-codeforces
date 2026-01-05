#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int zeros=0;
    for(char c:s){
        if(c == '0')
            zeros++;
    }
    if( zeros%2 == 0){
        cout<<"BOB\n";
    }else if(zeros&1){
        if(zeros>1)
            cout<<"ALICE\n";
        else
            cout<<"BOB\n";
    }
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}