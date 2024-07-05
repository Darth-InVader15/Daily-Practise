class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int tred = red, tblue = blue;
        int ans = 0, anst = 0;
        int i = 0;

        while(++i)
        {
            if(i%2 == 0)
            {
                if(blue >= i)
                {
                    anst++;
                    blue -= i;
                }
                else break;
            }
            else
            {
               if(red >= i)
                {
                    anst++;
                    red -= i;
                }
                else break; 
            }  
        }
        i = 0;
        while(++i)
        {
            if(i%2 == 0)
            {
                if(tred >= i)
                {
                    ans++;
                    tred -= i;
                }
                else break;
            }
            else
            {
               if(tblue >= i)
                {
                    ans++;
                    tblue -= i;
                }
                else break; 
            }  
        }
        return max(ans,anst);
    }
};