#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int>get_best(vector<int>&arr){
    int mx1=-1,mx2=-1,mx3=-1;
    for(int i=0;i<arr.size();i++){
        if(mx1== -1 || arr[i]>arr[mx1]){
            mx3=mx2;
            mx2=mx1;
            mx1=i;
        }else if(mx2==-1 || arr[i]>arr[mx2]){
            mx3=mx2;
            mx2=i;
        }else if(mx3==-1 || arr[i]>arr[mx3]){
            mx3=i;
        }
    }return {mx1,mx2,mx3};
}
void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n),c(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)cin>>c[i];
    vector<int>bestA=get_best(a);
    vector<int>bestB=get_best(b);
    vector<int>bestC=get_best(c);

    long long maxsum=0;
    for(int x:bestA) {
        for(int y:bestB) {
            for(int z:bestC) {
                if(x!=y && y!=z && x!=z){
                    long long ans= (long long)a[x]+b[y]+c[z];
                    maxsum=max(maxsum,ans);
                }
            }
        }
    }
    cout<<maxsum<<endl;
    
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
