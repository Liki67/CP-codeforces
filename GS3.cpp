#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<pair<int,int>>ans;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=1;j<=arr[i];j++){
            if(arr[i]%j==0){
                cnt++;
            }
        }ans.push_back({cnt,arr[i]});
    }
    sort(ans.begin(),ans.end(),[](const pair<int,int>&a,const pair<int,int>&b){
        return a.first==b.first?a.second>b.second:a.first>b.first;
    });;
    for(int i=0;i<n;i++){
        cout<<ans[i].second<<" ";
    }
    cout<<endl;
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
