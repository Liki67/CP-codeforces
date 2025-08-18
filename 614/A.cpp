#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c,n;
        cin>>a>>b>>c>>n;
        int maxi=a;
        maxi=max({maxi,b,c});
        n-=3*maxi-a-b-c;
        if(n>=0 && n%3 == 0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
