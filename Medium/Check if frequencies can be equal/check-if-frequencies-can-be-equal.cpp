//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    if(s.size() <= 1)   return 1;
	    vector<int> arr(26,0);
	    
	    for(auto x:s)   arr[x-'a']++;
	    sort(arr.begin(),arr.end(),greater<int>());
	   //for(int)
	   
	   //for(auto x:arr)  mpp[x]++
	    
	    
	    
	   
	    
	    int cnt = 0, endd=0;
	    for(int i=0;i<25;i++)
	    {
	        
	        if(arr[i+1] == 0)
	        {
	            endd = i;
	            break;
	        }
	        if(arr[i] - arr[i+1] == 1)  cnt++;
	        else if(arr[i] == arr[i+1]) continue;
	        else return 0;
	        
	        if(cnt > 1) return 0;
	    }
	    int mxx = 0, nmxx=0;
	    for(int i=0;i<=endd;i++)
	    {
	       if(arr[i] == arr[0])  mxx++;
	       else nmxx++;
	    }
	    
	    if(mxx > 1  && nmxx > 0) return 0;
	    return cnt<=1;
	    // 3 3 2 2
	    
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends