//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
    void solve(int x,int y, int dir, vector<vector<int>> &arr, vector<int> &ans)
    {
        //dir == 0 we go up else we go down 
        int n = arr.size();
        
        ans.push_back(arr[x][y]);
        
        if(x == n-1 && y == n-1)    return;
        
        if(!dir)
        {
            //we go up
            if(x+1 < n && y-1 >=0)  solve(x+1,y-1,dir,arr,ans);
            else
            {
                if(x+1 == n && y-1 < 0) solve(x,y+1,1,arr,ans);
                else if(x+1 == n)       solve(x,y+1,1,arr,ans);
                else                    solve(x+1,y,1,arr,ans);
            }
        }
        else
        {
            //we going down
            if(x-1 >= 0 && y+1 < n) solve(x-1,y+1,dir,arr,ans);
            else
            {
                if(x-1 < 0 && y+1 == n) solve(x+1,y,!dir,arr,ans);
                else if(x-1 < 0)        solve(x,y+1,!dir,arr,ans);
                else                    solve(x+1,y,!dir,arr,ans);
            }
        }
    }
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        vector<int> ans;
        solve(0,0,1,mat,ans);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends