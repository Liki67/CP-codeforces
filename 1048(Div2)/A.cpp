#include<iostream>
using namespace std;
int helper(int a, int b) {
    if( a == b )return 0;
    if(a<b && b%a == 0 || a>b && a%b == 0){
        return 1;
    }else {
        return 2;
    }return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        cout<<helper(a,b)<<endl;
    }
    return 0;
}
