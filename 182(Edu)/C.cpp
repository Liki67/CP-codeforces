#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool nonDesc(vector<int>c,vector<int>d,int n){
    for(int i=1;i<n;i++){
        if(c[i]<c[i-1] && d[i]<d[i-1])return false;
    }return true;
}
int check(vector<int>a,vector<int>b,int n){
    
    int cnt=0;
    if(nonDesc(a,b,n))cnt++;
    for(int i=0;i<n;i++){
        vector<int>c=a,d=b;
        for(int j=i;j<n;j++){
            swap(c[i],d[i]);
            if(nonDesc(c,d,n)){
                cnt++;
            }
        }
    }return cnt;
}
void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    cout<<check(a,b,n)<<endl;
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
