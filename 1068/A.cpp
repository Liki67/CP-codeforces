#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int wake=0,ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')wake=k;
        else if(wake == 0)ans++;
        else wake--;
    }
    cout<<ans<<endl;
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
