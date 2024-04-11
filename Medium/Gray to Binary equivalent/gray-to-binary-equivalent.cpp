//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    int binaryToDecimal(string &n)
    {
        // int num = n;
        int dec_value = 0;
     
        // Initializing base value to 1, i.e 2^0
        int base = 1;
     
        // int temp = num;
        for(int i=1;i<=n.size();i++) {
            
            int last_digit = (n[n.size()-i]) - '0';
     
            dec_value += last_digit * base;
     
            base = base * 2;
        }
     
        return dec_value;
    }
    
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        string bin = "";
        
        while(n)
        {
            bin += n%2 == 0 ? '0' : '1';
            n /= 2;
        }
        while(bin.size() < 3)   bin += '0';
        reverse(bin.begin(),bin.end());
        
        // cout<<bin<<" --\n";
        // return -1;
        
        string gray = "";
        
        gray += bin[0];
        
        for(int i=1;i<bin.size();i++)
        {
            // gray += ((bin[i-1]-'0') ^ (bin[i] - '0')) + '0'; 
            // int dig = gray[i-1] - '0';
            
            // if(bin[i] == '1')   gray[i] = (!dig) + '0';
            // else gray[i] = dig + '0';
            
            if(bin[i] == '1')
            {
                if(gray[i-1] == '0')    gray += '1';
                else gray += '0';
            }
            else
            {
                if(gray[i-1] == '0')    gray += '0';
                else gray += '1';
            }
        }
        // cout<<gray<<endl;
        // return -1;
        
        long long num = binaryToDecimal(gray);
        return num;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends