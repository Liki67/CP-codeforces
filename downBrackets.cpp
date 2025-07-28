#include<iostream>
#include<stack>
using namespace std;
string findDownBrackets(string s) {
    stack<char>st;
    int cnt=0;
    for(auto &c:s){
        if(st.empty())
            cnt++;
        if(cnt>1)
            return "yes";
        if(c == '(')
            st.push(c);
        else {
            if (!st.empty()) 
                st.pop();
        }
    }return "no";
}
int main(){
    string s;int t;
    cin>>t;
    while(t--){
        cin>>s;
        cout<<findDownBrackets(s);
    }
    
    return 0;
}