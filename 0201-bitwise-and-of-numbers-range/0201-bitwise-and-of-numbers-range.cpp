class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //let x be a power of 2
        // if lt is less than x and right is more than x then our ans will be 0

        if(left && right){
        
            int lt = log2(left);
            int rt = log2(right);
        
            if(lt != rt)    return 0;
            else
            {
                int ans = left;
                while(left <= right)
                {
                    ans &= left;
                    if(left < INT_MAX)
                    left++;
                    else break;
                }
                return ans;
            }

        }
        else    return 0;
        
    }
};