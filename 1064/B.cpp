#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
void solve(){
    int a,b,n;
    cin>>a>>b>>n;

    if((long long)b*n <=a || b>=a)cout<<1<<endl;
    else cout<<2<<endl;

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
