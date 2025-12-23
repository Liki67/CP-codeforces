#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    stack<char>st;
    for(int i=0;i<s.length();i++) {
        if(!st.empty() && st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    }
    if(st.empty())cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
