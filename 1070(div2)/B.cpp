#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    int i=0;
    int maxzeros=0;
    if(s[i]!='1'){
        while(i<n && s[i]=='0'){
            cnt++;
            i++;
        }
        int j=n-1;
        while(s[j]!='1'){
            cnt++;
            j--;
        }
        maxzeros=max(maxzeros,cnt);
    }
        for(int j=i;j<n;j++){
            if(s[j]=='1')
                cnt=0;
            else
                cnt++;
            maxzeros=max(maxzeros,cnt);
        }  
    
        cout<<maxzeros<<endl;
    


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
