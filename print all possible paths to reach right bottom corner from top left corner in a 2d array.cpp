#include <bits/stdc++.h>
using namespace std;

void helper(int i,int j,int r,int c,int arr[][],vector<int>v)
{
    if(i==r-1 && j==c-1)
    {   
        v.push_back(arr[i][j]);
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    if(i<r && j<c)
    {   
        v.push_back(arr[i][j]);
        helper(i,j+1,r,c,arr,v);
        helper(i+1,j,r,c,arr,v);
    }
    
}
int main()
{   
    int r,c;
    cout<<"enter the value of r,c\n";
    cin>>r>>c;
    int arr[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    vector<int>v;
    helper(0,0,r,c,arr,v);

    return 0;
}
