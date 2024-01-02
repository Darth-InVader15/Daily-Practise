//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string str)
{ 
    int n = str.size();
    string ans = "";
    char ch = str[0];
    int cnt = 1;
    
    if(n==1)
    {
        ans += ch;
        ans += to_string(cnt);
        return ans;
    }
    
    for(int i=1;i<n;i++)
    {
        if(str[i] == ch)
        {
            cnt++;
        }
        
        else
        {
            ans += ch;
            ans += to_string(cnt);
            
            ch = str[i];
            cnt = 1;
        }
        
        if(i == n-1)
        {
            ans += ch;
            ans += to_string(cnt);
        }
        
    }
    return ans;
  
}     
 
