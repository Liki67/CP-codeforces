#include<iostream>
#include<vector>
using namespace std;
int findArray(int n , vector<int>& a){
    int cnt=1,lastNum=a[0];
        for(int i=1;i<n;i++){
            if(lastNum+1<a[i]){
                cnt++;
                lastNum=a[i];
            }
        }
    return cnt;
}

int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<findArray(n,a);
    }
    
    return 0;
}