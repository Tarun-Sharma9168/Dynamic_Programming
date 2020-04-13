#include<iostream>
using namespace std;
int subsequence_count(string s,string t)
{
    if(s.length() < t.length())
    {
        return 0;
    }
    if(t.length()  == 0)
    {
        return 1;
    }
    if(s[0] == t[0])
    {
        int small_output=subsequence_count(s.substr(1),t.substr(1))+subsequence_count(s.substr(1),t);
        return small_output; 
    }
    if(s[0]!=t[0])
    {
        int small_output=subsequence_count(s.substr(1),t);
        return small_output;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
    string s;
    string t;
    cin>>s>>t;
    cout<<subsequence_count(s,t)<<"\n";
    }
    return 0;
}