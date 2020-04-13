#include<iostream>
using namespace std;
int max_count(int *arr,int n)
{
    int *dp=new int[n];
    if(n < 2)
    {
        return arr[0];
    }
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++)
    {
        dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
    }
    return dp[n-1];
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
        cin>>n;

        int arr[n]={0};
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
     int res=max_count(arr,n);
     cout<<res<<"\n";
    }
    return 0;
}