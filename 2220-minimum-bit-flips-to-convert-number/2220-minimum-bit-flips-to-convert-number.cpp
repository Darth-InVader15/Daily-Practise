class Solution {
public:
    int minBitFlips(int start, int goal) {
        int tar = start ^ goal;
        return __builtin_popcount(tar);
    }
};