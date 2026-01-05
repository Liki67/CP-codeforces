#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;


void solve() {
    int n,x;
    cin>>n>>x;

    vector<int>shop(n);
    for(int i=0;i<n;i++)cin>>shop[i];

    sort(shop.begin(),shop.end());
    for(int i=1;i<n;i++){
        shop[i]+=shop[i-1];
    }

    long long res=0;
    for(int i=0;i<n;i++) {
        if(shop[i]>x)break;
        int rem=x-shop[i];
        res=res+(rem/(i+1))+1;
    }cout<<res<<endl;
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