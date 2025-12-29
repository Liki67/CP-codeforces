#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<climits>
#include<stack>
#include<cmath>

using namespace std;

int check(int a, int b) {
    bool turnA = true;
    int up = 0;
    while (a >= 0 && b >= 0) {
        int val = (1 << up);
        if (turnA) {
            a -= val;
        } else {
            b -= val;
        }

        if (a < 0 || b < 0) break;
        turnA = !turnA;
        up++;
    }
    return up;
}

void solve() {
    int a,b;
    cin>>a>>b;

    int ans=max(check(a,b),check(b,a));
    cout<<ans<<endl;

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