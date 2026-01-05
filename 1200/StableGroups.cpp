#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;


void solve() {
    
    long long n,k,x;
    cin>>n>>k>>x;

    vector<long long>a(n+1);

    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    vector<long long>dif;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1] > x){
            dif.push_back(a[i]-a[i-1]);
        }
    }

    int groups=1;
    for(int i=0;i<dif.size();i++) {
        int needed=(dif[i]-1)/x;
        if(k>=needed){
            k-=needed;
        }else
        {
            groups++;
        }
    }
    cout<<groups<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    
        solve();
    
    return 0;
}