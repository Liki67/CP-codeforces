#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;

void solve() {
    int n,q;
    cin>>n>>q;

    vector<int>a(n+1);
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<bool>cAgain(n+1,false);

    vector<int>ans;bool changed=false;
    for(int i=0;i<q;i++) {
        int x;cin>>x;
        if(x == 1){
            int y,z;
            cin>>y>>z;
            if(changed && !cAgain[y]){
                sum=sum-two+z;
                ans.push_back(sum);
                a[y]=z;
                cAgain[y]=true;
            }else{
                sum= sum-a[y]+z;
                ans.push_back(sum);
                a[y]=z;
            }
            
        }else{
            int y;
            cin>>y;
            sum=n*y;
            ans.push_back(sum);
            two=y;
            changed=true;
        }
    }
    for(int x:ans)cout<<x<<endl;



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   solve();
    return 0;
}