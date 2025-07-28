#include<iostream>
#include<vector>
using namespace std;
int findMaxLen(int n, vector<int>&arr) {
    int l=0,r=n-1;
    while(l<r){
        int m=(l+r)/2;
        if(arr[l]>arr[r]){
            if(arr[m]>=arr[l])
                l=m+1;
            else
                r=m;
        }
        else return l;
    }return l;
}
int main(){
    int n,target;
    cout<<"enter the array size and target";
    cin>>n;
    cin>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxlen=findMaxLen(n,arr);
    cout<<maxlen;
    return 0;
}