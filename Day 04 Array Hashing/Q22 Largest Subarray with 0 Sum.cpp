//Q22 Largest Subarray with 0 Sum

//Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5

//Approach 1 : Naive Approach

// Intuition: We are required to find the longest subarray that sums to zero. So our initial approach could be to consider all possible subarrays of the given array and check for the subarrays that sum to zero. Among these valid subarrays (sum equal to zero) we’ll return the length of the largest subarray by maintaining a variable, say max.   


// Time Complexity: O(N^2) as we have two loops for traversal

// Space Complexity : O(1) as we aren’t using any extra space.



//Approach 2: Prefix Sum and Hashing

// Intuition:  Now let’s say we know that the sum of subarray(i, j) = S, and we also know that sum of subarray(i, x) = S where i < x < j. We can conclude that the sum of subarray(x+1, j) = 0.

// Let us understand the above statement clearly


// So in this problem, we’ll store the prefix sum of every element, and if we observe that 2 elements have same prefix sum, we can conclude that the 2nd part of this subarray sums to zero

// Now let’s understand the approach

{
	unordered_map<int,int> mpp; 
	int maxi = 0;
	int sum = 0; 
	for(int i = 0;i<n;i++) {
	    sum += A[i]; 
	    if(sum == 0) {
	        maxi = i + 1; 
	    }
	    else {
	        if(mpp.find(sum) != mpp.end()) {
	            maxi = max(maxi, i - mpp[sum]); 
	        }
	        else {
	            mpp[sum] = i;
	        }
	    }   
	}

	return maxi; 

}

//Time Complexlity : O(N)
//Space Complexity : O(N)
