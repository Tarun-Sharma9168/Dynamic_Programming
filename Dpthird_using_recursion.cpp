#include<iostream>
using namespace std;
long long int count_steps(long long int n)
{
 if( n<0)
 {
     return 0;
 }
 if(n==0)
 {
     return 1;
 }
 long long int small_output=count_steps(n-1)+count_steps(n-2)+count_steps(n-3);
 return small_output;
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
     long long  int n;
        cin>>n;
     long long int res=count_steps(n);
     cout<<res<<"\n";  
    }
return 0;
}