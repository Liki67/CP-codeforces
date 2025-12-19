#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int y,r;
    cin>>y>>r;
    int ans=0;
    ans+=r;
    ans+=y/2;
    if(ans>n)cout<<n<<endl;
    else cout<<ans<<endl;
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
