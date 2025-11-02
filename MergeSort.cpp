#include<iostream>
#include<vector>
#include<string>
using namespace std;
int cnt=0;
void mergeSort(int low, int mid, int high, vector<int>&arr){
    vector<int>temp;
    int l=low,r=mid+1;
    while(l<=mid && r<=high){
        if(arr[l]<arr[r]){
            temp.push_back(arr[l++]);
            cnt++;
        }else{
            temp.push_back(arr[r++]);
        }
    }
    while(l<=mid)temp.push_back(arr[l++]);
    while(r<=high)temp.push_back(arr[r++]);
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void merge(int low, int high, vector<int>& arr) {
    if(low>=high)return;
    int mid=low+(high-low)/2;
        merge(low,mid,arr);
        merge(mid+1,high,arr);
        mergeSort(low,mid,high,arr);
    
}
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    merge(0,n-1,arr);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<cnt;
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
