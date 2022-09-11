#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    long long n,k;
	    cin>>n>>k;
	    long long int x=0,p;
	    for(long long j=1;j<=k;j++)
	    {
	        int l;
	        cin>>l;
	        if(j==1)
	        {
	            x += l-1;
	            x = x/2;
	            p=l;
	            continue;
	        }
	        x += l-p-1;
	        p=l;
	        x = x/2;
	    }
	    x+=n-p;
	    long long  c=0;
	    while(x)
	    {
	        if(x&1)
	        {
	            c++;
	        }
	        x=x>>1;
	    }
	   
	    long long int res=(n-k)-c;
	    cout<<res<<"\n";
	      
	}
	return 0;
}
