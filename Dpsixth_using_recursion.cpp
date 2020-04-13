#include<iostream>
using namespace std;
int maximizeTheCuts(int n, int x, int y, int z)
{
    int res=INT32_MIN;
    if(n==0)
    {
        return 0;
    }
    if(x <= n)
    {
        int small_output=maximizeTheCuts(n-x,x,y,z);
        if(small_output!=INT32_MIN && small_output+1 > res)
        {
            res=small_output+1;
        }
    }
    if(y <= n)
    {
        int small_output=maximizeTheCuts(n-y,x,y,z);
        if(small_output!=INT32_MIN && small_output+1 > res)
        {
            res=small_output+1;
        }
    }
    if(z <= n)
  {  
        int small_output=maximizeTheCuts(n-z,x,y,z);
        if(small_output!=INT32_MIN && small_output+1 > res)
        {
            res=small_output+1;
        }
    }
    return res;
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
         int n;
         int x,y,z;
         cin>>n>>x>>y>>z;
         int res=maximizeTheCuts(n,x,y,z);
         cout<<res<<"\n";
    }
return 0;
}