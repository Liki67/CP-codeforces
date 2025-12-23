#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPowerOfTwo(long long n) {
    if((n & (n-1)) == 0)return true;
    return false;
}
void solve() {
    long long n, k;
    cin >> n >> k;
    if (k & 1) {
        for (int i = 0; i < k; i++) cout << n << " ";
        cout << "\n";
    } else {

            for (int i = 0; i < k - 2; i++) {
                cout << n << " ";
            }

            if (isPowerOfTwo(n)) {
                
                cout << n << " " << 0 << "\n";
            } else {
                long long a=n,b=0,max=0;
                for( long long x=n-1;x>n/2;x--){
                    if(x+(a^x) > max){
                        b=a^x;
                        a=x;
                        max=a+b;
                    } if(isPowerOfTwo(x)){
                        break;
                    }
                }

                cout << a << " " << b << "\n";
            }
        

        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}