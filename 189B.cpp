#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), temp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
vector<int> f(n, 0);
stack<int> st;
int ans = 0;

for (int i = 0; i < n; i++) {
    int t = 0;
    while (!st.empty() && a[st.top()] < a[i]) {
        t = max(t, f[st.top()]);
        st.pop();
    }
    if (st.empty()) {
        f[i] = 0;
    } else {
        f[i] = t + 1;
    }
    st.push(i);
    ans = max(ans, f[i]);
}
cout << ans << "\n";
    return 0;
}