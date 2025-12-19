#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;
void solve(){
    int l,a,b;
    cin>>l>>a>>b;
    unordered_map<int,int>ump;

    int i=1,ans=0,val=0;
    while(true) {
        val=(a+i*b)%l;
        if(ump[val]){
            cout<<ans<<endl;
            return;
        }
        ump[val]=1;
        ans=max(ans,val);
        i++;
    }

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
