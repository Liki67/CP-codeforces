#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int x,y,z;
    cin>>x>>y>>z;
    if((x&y) == (y&z) && (y&z) == (x&z))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
