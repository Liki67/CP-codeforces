#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
using namespace std;
using ll = long long;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    unordered_map<int,int>ump;
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
        ump[a[i]]=1;
    }
    
    vector<int>b;
    
    while(s.size()) {
        int t=*s.begin();
        b.push_back(t);
        s.erase(s.begin());
        for(int i=t;i<=k;i+=t){
            if(!ump[i]){
                cout<<-1<<endl;
                return;
            }
            auto u=s.find(i);
            if(u!=s.end())s.erase(u);
        }
    }

    cout<<b.size()<<endl;
    for(int i=0;i<b.size();i++)cout<<b[i]<<" ";
    cout<<endl;
    
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
