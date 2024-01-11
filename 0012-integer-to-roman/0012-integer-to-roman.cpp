class Solution {
public:
    string intToRoman(int num) {
        string str = to_string(num);
        int n = str.size();
        string ans = "";
        int i = 0;
        
        if(n == 4)
        {
            int dig = str[i] - '0';
            while(dig--)    ans += "M";
            n--;
            i++;
        }
        if(n == 3)
        {
            int dig = str[i] - '0';
            i++;
            if(dig < 4)
            {
                while(dig--)    ans+= "C";
            }
            else if(dig == 4)   ans+= "CD";
            else if(dig == 9)   ans+= "CM";
            else
            {
                ans+="D";
                dig-=5;
                while(dig--)    ans+= "C";
            }
            n--;
        }
        
        if(n == 2)
        {
            int dig = str[i] - '0';
            i++;
            if(dig < 4)
            {
                while(dig--)    ans+= "X";
            }
            else if(dig == 4)   ans+= "XL";
            else if(dig == 9)   ans+= "XC";
            else
            {
                ans+="L";
                dig-=5;
                while(dig--)    ans+= "X";
            }
            n--;
        }
        if(n == 1)
        {
            int dig = str[i] - '0';
            // cout<<dig<<endl;
            i++;
            if(dig < 4)
            {
                while(dig--)    ans+= "I";
            }
            else if(dig == 4)   ans+= "IV";
            else if(dig == 9)   ans+= "IX";
            else
            {
                ans+="V";
                dig-=5;
                while(dig--)    ans+= "I";
            }
            n--; 
        }
        return ans;
        
    }
};