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
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];

    int maxi=n,mini=n;
    if(a[maxi]>=a[n-1])maxi=n-1;
    if(a[mini]<=a[n-1])mini=n-1;
    vector<tuple<int,int,int>>ans;
    for(int i=n-2;i>0;i--) {
        int ind=-1;
        int ele;
        if(a[i]>0){
            ele=a[i]-a[mini];
            ind=maxi;
        }else{
            ele=a[i]-a[mini];
            ind=mini;
        }
        if(i-1>1){
            if(ele>a[i-2] && ele<a[i-1]){
                ans.push_back({i-1,i,ind});
            }
        }else if(ele<a[i-1]){
            ans.push_back({i-1,i,ind});
        }
        if(a[maxi]>=a[i])maxi=i;
        if(a[mini]<=a[i])mini=i;

    }
    if(ans.empty())cout<<-1<<endl;
    else{
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++) {
            cout<<get<0>(ans[i])<<get<1>(ans[i])<<get<2>(ans[i])<<endl;
        }
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