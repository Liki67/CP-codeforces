#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
using namespace std;
void solve(){
    int n;
    cin>>n;vector<int>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int k;
    cin>>k;
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<n;i++){
        pq.push({a[i]-b[i],i});
    }int ans=0;
    if(n == k){}
    set<int>se;
    while(k--){
        int ind=pq.top().second;
        pq.pop();
        se.insert(ind);
        ans+=a[ind];
    }
    for(int j=0;j<n;j++){
        if(se.find(j)==se.end()){
            ans+=b[j];
        }
    }cout<<ans<<endl;
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
