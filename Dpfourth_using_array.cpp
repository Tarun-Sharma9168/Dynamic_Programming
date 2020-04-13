#include<iostream>
using namespace std;
int knapSack(int w,int *weight,int *values,int n)
{
    int k[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            {
                k[i][j]=0;
            }
            else if(weight[i-1] <= j)
            {
                 k[i][j] = max(values[i-1] + k[i-1][j-weight[i-1]],k[i-1][j]); 
            }
            else
            {
                   k[i][j] = k[i-1][j]; 
            }
        }
    }
return k[n][w];
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

           int values[n]={0};
           int weight[n]={0};
           int w;
           cin>>w;
           for(int i=0;i<n;i++)
           {
                  cin>>values[i];
           }

           for(int i=0;i<n;i++)
           {
                  cin>>weight[i];
           }
           int res= knapSack(w,weight,values,n);
           cout<<res<<"\n";
    }
    return 0;
}