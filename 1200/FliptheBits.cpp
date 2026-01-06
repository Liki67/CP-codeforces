#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>

using namespace std;
void solve() {
    int n;
    cin>>n;

    string a,b;
    cin>>a>>b;

    vector<bool>same(n,false);
    int ones=0,zeros=0;
    for(int i=0;i<n;i++){
        if(a[i] == '1')ones++;
        else zeros++;
        if(zeros == ones){
            same[i]=true;
        }
    }

    int flips=0;
    for(int i=n-1;i>=0;i--) {
        char cur = a[i];
        if (flips & 1) {
            cur = (cur == '1' ? '0' : '1');
        }
        if(!same[i]){
            if(cur!=b[i]){
                cout<<"NO\n";
                return;
            }
        }else{
            if(cur != b[i]){
                flips++;
            }
        }
    }
    cout<<"YES\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}