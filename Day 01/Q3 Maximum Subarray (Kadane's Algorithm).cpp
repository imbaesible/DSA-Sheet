// Q3. Maximum Subarray (Kadane's Algorithm)

// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// A subarray is a contiguous part of an array.

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.



//Approach 1: Naive Approach 

// Using three for loops, we will get all possible subarrays in two loops and their sum in another loop, and then return the maximum of them.

int maxSubArray(vector < int > & nums, vector < int > & subarray) {
  int max_sum = 0;
  int n = nums.size();
  if (n == 1) {
    return nums[0];
  }
  int i, j;
  for (i = 0; i <= n - 1; i++) {
    for (j = i; j <= n - 1; j++) {
      int sum = 0;
      for (int k = i; k <= j; k++)
        sum = sum + nums[k];
      if (sum > max_sum) {
        subarray.clear();
        max_sum = sum;
        subarray.push_back(i);
        subarray.push_back(j);

      }
    }
  }
  return max_sum;
}

// Time Complexity: O(N^3) 
// Space Complexity: O(1)

// Approach 2: A better approach (Using 2 Loops only)

// We can also do this problem using only two for loop, starting the function with ( max_sum ) variable which will have the final answer. We can get the sum of all possible subarrays in this way and then return the maximum so far.

int maxSubArray(vector < int > & nums, vector < int > & subarray) {
  int max_sum = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    int curr_sum = 0;
    for (int j = i; j < nums.size(); j++) {
      curr_sum += nums[j];
      if (curr_sum > max_sum) {
        subarray.clear();
        max_sum = curr_sum;
        subarray.push_back(i);
        subarray.push_back(j);
      }
    }
  }
  return max_sum;
}

// Time Complexity: O(N^2) 
// Space Complexity: O(1)

// Approach 3 : Optimal Solution: Kadane's Algorithm

// Intuition: Basically this problem can be done in linear time complexity with Kadane’s algorithm along with that will also get the subarray which is giving the largest positive-sum. 

int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int maxsum = INT_MIN;
    
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        maxsum = max(maxsum, sum);
        if(sum<0) sum = 0;
    }
    
    return maxsum;
}

//with subarray approach

int maxSubArray(vector < int > & nums, vector < int > & subarray) {
  int msf = nums[0], meh = 0;
  int s = 0;
  for (int i = 0; i < nums.size(); i++) {
    meh += nums[i];
    if (meh > msf) {
      subarray.clear();
      msf = meh;
      subarray.push_back(s);
      subarray.push_back(i);

    }
    if (meh < 0) {
      meh = 0;
      s = i + 1;

    }
  }

  return msf;
}

// Time Complexity: O(N) 
// Space Complexity:O(1)






