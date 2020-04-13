#include<iostream>
using namespace std;
long long int count_no_ways(long long int n)
{
    long long int dp[n+1]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i]+dp[i-1];
        if(i>=2)
        {
            dp[i]+=dp[i-2];
        }
        if(i>=3)
        {
            dp[i]+=dp[i-3];
        }
    }
    return dp[n];
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
        long long int n;
        cin>>n;
        cout<<count_no_ways(n)<<"\n";
    }
return 0;
}
