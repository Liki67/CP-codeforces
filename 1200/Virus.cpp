#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;

void solve() {
    int n,m;
    cin>>n>>m;
    
    vector<int>a(m);
    for(int i=0;i<m;i++)cin>>a[i];
    sort(a.begin(),a.end());

    vector<int>diff(m);
    for(int i=0;i<m-1;i++){
        diff[i]=a[i+1]-a[i]-1;
    }
    diff[m-1]=(a[0]-1)+(n-a[m-1]);
    sort(diff.rbegin(),diff.rend());

    int days=0,save=0;
    for(int i=0;i<m;i++) {
        int gap=diff[i]-2*days;
        if(gap<=0)continue;
        if(gap ==1 || gap==2){
            save+=1;
            days++;
        }else{
            save+=gap-1;
            days+=2;
        }
    }
    cout<<n-save<<endl;
   
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}