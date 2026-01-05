#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<string>a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    int cnt=0;
    for(int i=0;i<=n/2;i++) {
        for(int j=i;j<n-i-1;j++) {
            int zeros=0,ones=0;
            if(a[i][j]=='0')zeros++;
            else ones++;
            if(a[j][n-i-1]=='0')zeros++;
            else ones++;
            if(a[n-i-1][n-j-1]=='0')zeros++;
            else ones++;
            if(a[n-j-1][i]=='0')zeros++;
            else ones++;
            
            cnt+=min(zeros,ones);
        }
    }
    cout<<cnt<<endl;


}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}