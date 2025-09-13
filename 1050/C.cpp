#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(int n,int m,vector<int>&a,vector<int>&b){
    int ans=0,currT=0,currPos=0;
    for(int i=0;i<n;i++){
        int time=a[i]-currT;
        if(b[i] == (currPos+time)%2){
            ans+=time;
        }else{
            ans+=time-1;
        }currT=a[i];
        currPos=b[i];
    }
    if(a[n-1]<m){
        ans+=m-a[n-1];
    }
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) {
       int n,m;
        cin>>n>>m;
       vector<int>a(n),b(n);
       for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
       }
       solve(n,m,a,b);
    }
    return 0;
}
