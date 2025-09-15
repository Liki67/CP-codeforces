#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int zero_cnt=0;
    for(auto c:s){
        if(c == '0')
            zero_cnt++;
    }
    int mis_ones=0;
    for(int i=0;i<zero_cnt;i++){
        if(s[i] == '1')
            mis_ones++;
    }cout<<mis_ones<<endl;
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
