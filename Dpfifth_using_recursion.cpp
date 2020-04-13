#include<iostream>
using namespace std;
int coin_exchange(int coins[], int m, int V) 
{ 
   // base case 
   if (V == 0) return 0; 
  
   // Initialize result 
   int res = INT32_MAX; 
  
   // Try every coin that has smaller value than V 
   for (int i=0; i<m; i++) 
   { 
     if (coins[i] <= V) 
     { 
         int sub_res = coin_exchange(coins, m, V-coins[i]); 
  
         // Check for INT_MAX to avoid overflow and see if 
         // result can minimized 
         if (sub_res != INT32_MAX && sub_res + 1 < res) 
            res = sub_res + 1; 
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