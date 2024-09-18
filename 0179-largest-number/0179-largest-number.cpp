/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    // Convert integers to strings
    let array = nums.map(String);
    
    // Custom sorting with a comparator function
    array.sort((a, b) => (b + a).localeCompare(a + b));
    
    // Handle the case where the largest number is "0"
    if (array[0] === "0") {
        return "0";
    }
    
    // Build the largest number from the sorted array
    return array.join('');
};