#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a(n,' ');
        cin>>a;
        int m;cin>>m;
        string b(m,' '),c(m,' ');
        cin>>b;
        cin>>c;
        string res=a;
        for(int i=0;i<m;i++){
            if(c[i] == 'D'){
                res+=b[i];
            }else{
                res=b[i]+res;
            }
        }
        cout<<res<<endl;

    }
    return 0;
}
