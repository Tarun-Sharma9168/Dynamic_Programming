#include<iostream>
#include<vector>
using namespace std;
int maximizeTheCuts(int n, int x, int y, int z)
{
 int table[n+1];
 table[0]=0;
 for(int i=1;i<=n;i++)
 {
     table[i]=INT32_MIN;
 }
 vector<int> vv;
 vv.push_back(x);
 vv.push_back(y);
 vv.push_back(z);
 for(int i=1;i<=n;i++)
 {
     for(int j=0;j<vv.size();j++)
     {
         if(vv[j] <= i)
         {
             int res=table[i-vv[j]];
             if(res!=INT32_MIN && res+1 > table[i])
             {
                 table[i]=res+1;
             }
         }
     }
 }
 if(table[n]==INT32_MIN)
 {
     return 0;
 }
else
return table[n];
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
          int x,y,z;
          cin>>x>>y>>z;

          int res=maximizeTheCuts(n,x,y,z);
          if(res == INT32_MIN)
          {
              cout<<"0"<<"\n";
          }
          else{
              cout<<res<<"\n";
          }
    }
    return 0;
}