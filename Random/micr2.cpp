#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
void solve(string s){
    int n=s.length();
    int power=n-1;int ans=0;
    for(int i=0;i<n;i++){
        ans+=(s[i]-'0')*pow(2,power);
        power--;
    }
    int cnt=0;
    while(ans) {
        if(ans%2 == 0){
            ans=ans/2;
        }else{
            ans-=1;
        }cnt++;
    }cout<<cnt<<endl;
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        solve(s);
    }
    return 0;
}
