#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void helper(string s,vector<string>&ans,string temp,vector<int>&visited,int n){
	        if(temp.size() == n){
	            ans.push_back(temp);
	        }
	        else{
	            for(int i = 0;i<n;i++){
	                if(visited[i] != 1){
	                    temp.push_back(s[i]);
	                    visited[i] = 1;
	                    helper(s,ans,temp,visited,n);
	                    temp.pop_back();
	                    visited[i] = 0;
	                }
	            }
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string>ans;
		    string temp;
		    int n = s.size();
		    vector<int>visited(n,0);
		    helper(s,ans,temp,visited,n);
		    set<string>st;
		    vector<string> :: iterator it = ans.begin();
		    for(;it != ans.end();it++){
		        st.insert(*it);
		    }
		    ans.clear();
		    set<string> :: iterator it2 = st.begin();
		    for(;it2 != st.end();it2++){
		        ans.push_back(*it2);
		    }
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
