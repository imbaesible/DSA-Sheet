// Q1. Best Time to Buy and Sell Stock

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


// Approach 1 :  Brute-Force Solution

// We can use to loops and check the difference of each day and store it in a variable and then return the max profit.

// for(int i = 0; i<arr.length; i++){
// 	for(int j=i+1; j<arr.length; j++){
// 		prof = a[j] - a[i];
// 		maxProf = max(prof, maxProf);
// 	}
// }

// Time Complexity : O(N^2)
// Space Complexity : O(1)

//Approach 2 :

// We can create a variable to store minimum buying value and them gradually check for max profit from the buying day (which was minimum) and store the value in profit variable and then later return the maximum profit.

int maxProfit(vector<int>& arr) {
    int min = arr[0]; 
    int profit=0, maxprofit=0; 
    for(int i=1; i<arr.size(); i++){
        if(arr[i]<min) min = arr[i];
        else{
            profit = arr[i]-min;
            maxprofit = max(maxprofit, profit);
        }
    }
    
    return maxprofit;
}

// Time Complexity : O(N)
// Space Complexity : O(1)
