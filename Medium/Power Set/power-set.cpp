//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    void trav(int ind, vector<string> &ans, string &str, string &anss)
    {
        if(ind >= str.size())   return;
        
        //take
        anss += str[ind];
        ans.push_back(anss);
        trav(ind+1,ans,str,anss);
        anss.pop_back();
        
        //dont
        trav(ind+1,ans,str,anss);
    }
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    string anss = "";
		    int n = s.size();
		    
		    trav(0,ans,s,anss);
		    sort(ans.begin(),ans.end());
		    
		    return ans;
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends