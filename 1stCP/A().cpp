#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int cnt=1;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        for(int i=0;i<n;i++) {
            if(a[i]>b[i]){
                 while(a[i]>b[i]){
                    a[i]=a[i]-1;
                    cnt++;
                }
            }
               
        }
        cout<<cnt<<endl;
    }
    return 0;
}
