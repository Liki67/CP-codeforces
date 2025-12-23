#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    unordered_map<char,int>ump;
    for(auto c:s){
        ump[c]++;
    }

    int freqN=ump[s[n-1]];
    cout<<n-freqN<<endl;

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
