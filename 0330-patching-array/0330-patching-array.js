/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number}
 */
var minPatches = function(nums, n) {
    let maxRange = 1;
    let cnt = 0, i=0;

    while(maxRange <= n)
    {
        if(i<nums.length && nums[i] <= maxRange)
        {
            maxRange += nums[i];
            i++;
        }
        else
        {
            maxRange *= 2;
            cnt++;
        }
    }
    return cnt
};