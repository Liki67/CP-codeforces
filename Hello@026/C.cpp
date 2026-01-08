#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;

void solve() {
    
    int n,m,k;
    cin>>n>>m>>k;

    if(k-1<n-k)k=n-k+1;
    int a=0,b=0;
    while(1){
        if(b+k<n && a+b+1+max(a,b+1)-1<=m)++b;
        if(a+1<k && a+b+1+max(a+1,b)-1<=m)++a;
        else break;
    }
    /*int ans=0;
    for(int i=1;i<=max(k-1,n-k);i++){
        if(i+k<n && ans+1+i-1<=m )++ans;
        if(k-i>1 && ans+1+i-1<=m)++ans;
        else break;
    }
    cout<<ans+1<<endl;*/
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