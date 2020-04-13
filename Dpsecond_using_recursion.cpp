#include<iostream>
using namespace std;
int max_count(int *arr,int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n == 1)
    {
        return arr[n-1];
    }
    int small_output=max(arr[0]+max_count(arr+2,n-2),max_count(arr+1,n-1));
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
         int n;
         cin>>n;
         int arr[n]={0};
         for(int i=0;i<n;i++)
         {
             cin>>arr[i];
         }
         int res= max_count(arr,n); 
         cout<<res<<"\n";
    }
return 0;
}