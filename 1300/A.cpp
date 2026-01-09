#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>
#include<map>

using namespace std;

void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    map<pair<int, int>, int> freq;
    long long beauty = 0; 

    for (int i = 0; i < n; i++) {
        int remX = a[i] % x;
        int remY = a[i] % y;

        int targetX = (x - remX) % x;
        int targetY = remY;

        if (freq.count({targetX, targetY})) {
            beauty += freq[{targetX, targetY}];
        }

        freq[{remX, remY}]++;
    }
    cout<<beauty<<endl;

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
