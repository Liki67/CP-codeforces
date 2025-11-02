#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<int>roll(n);
    for(int i=0;i<n;i++)cin>>roll[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<roll[i];j++){
            if(s[j] == 'z')s[j]='a';
            else
                s[j]=s[j]+1;
        }
    }
    cout<<s;

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
