#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<long long> ans;
void check(long long n) {
    if(n == 0)return;
    long long mod=10;
    while(mod<n){
        long long a=n/mod;
        while(a>0){
            long long x=a+a*mod;
            if(a*mod>n)break;
            if(x == n)
                ans.push_back(a);
            a--;
        }
        mod=mod*10;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        ans.clear();
        check(n);
        if(ans.empty())cout<<0<<endl;
        else{
            sort(ans.begin(),ans.end());
            for(long long i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }cout<<endl;
            
        }
    }

    return 0;
}