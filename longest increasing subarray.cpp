#include <bits/stdc++.h>
using namespace std;

int func(int s,int i ,int*a,int*dp)
{   
    
    int ans=1;
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    for(int j=s;j<i;j++)
    {
        if(a[i]>a[j])
        {
            ans=max(ans,func(s,j,a,dp)+1);
        }
    }
    return dp[i]=ans;
    
}
int main()
{
    cout<<"provide n\n";
    int n;
    cin>>n;
    int a[n];
    cout<<"provide array\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    
    int dp[n];
    memset(dp,-1,sizeof(dp));
    int s=0;
    for(int i=0;i<n;i++)
    {  
       if(i>0 && a[i]<a[i-1])
       {
           s=i;
       }
       ans=max(ans,func(s,i,a,dp)) ;
    }
    cout<<ans;
    
    return 0;
}
