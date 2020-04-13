#include<iostream>
using namespace std;
int knapSack(int w,int *weight,int *values,int n)
{   
    int sum=0;
    if(n == 0)
    {
        return 0;
    }
    if( weight[0] > w )
    {
        return knapSack( w , weight+1 , values+1 , n-1 );
    }
    sum = sum + ( max( values[0] + knapSack( w-weight[0] , weight+1 , values+1 , n-1) , knapSack( w , weight+1, values+1 , n-1) ));
    return sum;
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