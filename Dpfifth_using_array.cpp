#include<iostream>
using namespace std;
long long int coin_exchange(int *arr,int n,int money)
{
     int table[money+1];
     table[0]=0;

     for(int i=1;i<=money;i++)
     {
         table[i]=INT32_MAX;
     }
     for(int i=1;i<=money;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(arr[j]<= i)
             {
                 long long int res=table[i-arr[j]];
                 if(res!=INT32_MAX && res+1 < table[i])
                 {
                     table[i]=res+1;
                 }
             }
         }
     }
     return table[money];
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
          int n,money;
          cin>>money;  
          cin>>n;

          int arr[n]={0};
          for(int i=0;i<n;i++)
          {
                  cin>>arr[i];
          }
          int min_count=coin_exchange(arr,n,money);
          if(min_count == INT32_MAX)
          {
              cout<<"Not Possible"<<"\n";
          }
          else
          {
              cout<<min_count<<"\n";
          }
    }
    return 0;
}