//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool helper(int i,int a[],int n,bool v[],int cs,int target,int k,int count)
    {
        if(cs==target)
        {
            cs=0;
            count++;
            
            return helper(0,a,n,v,cs,target,k,count);
            
        }
        if(count ==k-1)
        {
            return true;
        }
        if(cs>target || i>=n)
        {
            return false;
        }
        
        if(v[i]==1)
        {
            return helper(i+1,a,n,v,cs,target,k,count);
        }
        else
        {
            v[i]=1;
            bool ak=helper(i+1,a,n,v,cs+a[i],target,k,count);
            v[i]=0;
            bool bk=helper(i+1,a,n,v,cs,target,k,count);
            
            return ak|bk;
        }
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         if(k==1)return true;
         int sum=0;
         for(int i=0;i<n;i++)
         {
             sum += a[i];
         }
         if(k>n || sum%k!=0)
         {
             return false;
         }
         else
         {   
             bool v[n]={0};
             int target=sum/k;
             return helper(0,a,n,v,0,target,k,0);
         }
    
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends
