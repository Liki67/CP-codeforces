
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>
#include<set>

using namespace std;

void solve() {
    int n;
    char c;
    cin>>n>>c;
    
    string s;
    cin>>s;

    bool contains=false;
    for(int i=0;i<n;i++){
        if(s[i]!=c)
            contains=true;
    }
    
    if(contains){
        if(s[n-1]!=c && s[n-2]!=c){
            cout<<2<<endl;
            cout<<n<<" "<<n-1<<endl;
        }else if(s[n-1]!=c){
            cout<<1<<endl;
            cout<<n-1<<endl;
        }else{
            cout<<1<<endl;
            cout<<n<<endl;
        }
    }else{
        cout<<0<<endl;
    }

    

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        solve();
    }
   
    return 0;
}