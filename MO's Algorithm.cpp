//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 struct Qu{
        int idx,l,r;
    };
int nn;
class Solution {
public:
    bool static compare(Qu &q1 , Qu &q2)
    {
        if(q1.l/nn == q2.l/nn)
        {
            return q1.r > q2.r ;
        }
        return q1.l/nn < q2.l/nn ;
    }
	vector<int>solveQueries(vector<int>n, vector<vector<int>>Q){
	    // Code here
	    unordered_map<int,int>v;
	    
	    int len = n.size();
	    int alen = 0;
	    int len2 = Q.size();
	    Qu qrr[len2];
	    nn = (int)sqrt(len)+1;
	    for(int i=0;i<len2;i++)
	    {
	        qrr[i].l = Q[i][0];
	        qrr[i].r = Q[i][1];
	        qrr[i].idx = i+1; 
	        
	    }
	    sort(qrr,qrr+len2,compare);
	    int cl =0;
	    int cr =-1;
	    int l ,r;
	    vector<int>ans(len2,0);
	    
	    for(int i = 0;i<len2;i++)
	    {
	        l = qrr[i].l ;
	        r = qrr[i].r ;
	        l--; r--;
	        
	        while(cr > r)
	        {   
	            int k = n[cr];
	            if( v[n[cr]] == k )
	            {
	                alen--;
	            }
	            v[n[cr]] = v[n[cr]] - 1;
	            if( v[n[cr]] == k)
	            {
	                alen++;
	            }
	            cr = cr -1;
	        }
	        while(cl < l)
	        {   
	            int k = n[cl];
	            if( v[n[cl]] == k )
	            {
	                alen--;
	            }
	            v[n[cl]] = v[n[cl]] - 1;
	            if( v[n[cl]] == k )
	            {
	                alen++;
	            }
	            cl = cl +1;
	        }
	        while(cl > l)
	        {   
	            
	            cl = cl - 1;
	            int k = n[cl];
	            if( v[n[cl]]==k )
	            {
	                alen--;
	            }
	            v[n[cl]] = v[n[cl]] + 1;
	            if( v[n[cl]]==k )
	            {
	                alen++;
	            }
	        }
	        while(cr < r)
	        {   
	            
	            cr = cr + 1;
	            int k = n[cr];
	            if( v[n[cr]]==k )
	            {
	                alen--;
	            }
	            v[n[cr]] = v[n[cr]] + 1;
	            if( v[n[cr]]==k )
	            {
	                alen++;
	            }
	        }
	        if(alen>0)
	        { 
	            ans[(qrr[i].idx)-1] = alen;
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
    
		int n, q;
		cin >> n >> q;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		vector<vector<int>>Queries;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Queries.push_back({l,r});
		}
		Solution obj;
		vector<int>ans = obj.solveQueries(nums, Queries);
		for(auto i: ans)cout << i << "\n";
	
	return 0;
}
// } Driver Code Ends