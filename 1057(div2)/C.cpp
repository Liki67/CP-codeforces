#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<unordered_set>
#include<queue>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    unordered_set<int>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s.count(a[i])){
            s.erase(a[i]);
            cnt+=2*a[i];
        }
        else s.insert(a[i]);
    }
    if(cnt == 0)cout<<0<<endl;
    else if(s.empty())cout<<cnt<<endl;
    else{
            vector<long long>ans(s.begin(),s.end());
            sort(ans.begin(),ans.end());long long prev;
            int m=ans.size()-1;
            if(n == 3&& !ans.empty()){if(ans[m]>=cnt){cout<<0<<endl;}}
            else{
                int j=m;
                while(j>=0){
                    if(ans[j]>=cnt)j--;
                    else{
                        cnt+=ans[j];
                        prev=ans[j];break;
                    }
                }j=m;
                while(j>=0){
                    if(ans[j]>=cnt ||ans[j] == prev)j--;
                    else {
                        cnt+=ans[j];break;
                    }
                }cout<<cnt<<endl;
            }
            
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
