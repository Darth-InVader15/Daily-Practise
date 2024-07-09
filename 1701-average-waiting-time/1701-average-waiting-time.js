/**
 * @param {number[][]} customers
 * @return {number}
 */
var averageWaitingTime = function(cunts) {
    var ans = 0.0;  
    const len = cunts.length;
    var chef = cunts[0][0]; //initially the chef is free
    //FCFS bitches!!!

    for(var i=0;i<len;i++)
    {
        let arr = cunts[i][0];
        let time = cunts[i][1];

        chef = Math.max(chef,arr);
        chef += time;
        // console.log(chef + " " + time);
        ans += (chef-arr);
        
         
    }
    ans = ans/len;
    return ans;

};