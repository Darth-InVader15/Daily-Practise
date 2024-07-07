class Solution {
public:
    int numWaterBottles(int bot, int ex) {
        int empty = 0;
        int ans = 0;

        while(bot)
        {
            ans += bot;
            empty += bot;
            bot = empty/ex;
            empty %= ex;
        }
        return ans;
    }
};