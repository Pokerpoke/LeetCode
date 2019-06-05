/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let res = 0;
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] > prices[i - 1])
            res += prices[i] - prices[i - 1];
    }
    return res;
};

let prices = [7, 1, 5, 3, 6, 4];
console.log(maxProfit(prices));

prices = [1, 2, 3, 4, 5];
console.log(maxProfit(prices));

prices = [7, 6, 4, 3, 1];
console.log(maxProfit(prices))