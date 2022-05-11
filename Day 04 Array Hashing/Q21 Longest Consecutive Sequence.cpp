//Q21 Longest Consecutive Sequence 

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.


// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.



// Approach 1 : Brute Force //more fast on leet code

// We can simply sort the array and run a for loop to find the longest consecutive sequence.

int longestConsecutive(vector<int> nums) {
    if(nums.size() == 0 ){
        return 0;
    }
    
    sort(nums.begin(),nums.end());
    
    int ans = 1;
    int prev = nums[0];
    int cur = 1;
    
    for(int i = 1;i < nums.size();i++){
        if(nums[i] == prev+1){
            cur++;
        }
        else if(nums[i] != prev){
            cur = 1;
        }
        prev = nums[i];
        ans = max(ans, cur);
    }
    return ans;
}

//Time Comlexity : O(N * logN) 
//Space Complexity : O(1)


//Appraoch 2 : (Optimal Approach) Using Hash Set

unordered_set<int> check(nums.begin(),nums.end());
int ans=0;

for(int i=0;i<nums.size();i++){
    if(check.find(nums[i]-1)==check.end()){
        int count=0;
        while(check.find(nums[i]+count)!=check.end())
            count++;
        ans=max(ans,count);
    }
}
return ans;



//TLE

// int longestConsecutive(vecotr<int> &nums){
// 	set<int> hashSet;
// 	for(int num : nums){
// 		hashSet.insert(num);
// 	}

// 	int longestStreak = 0;

// 	for(int num : nums){
// 		if(!hashSet.count(num - 1)){
// 			int currentNum = num;
// 			int currentStreak = 1;

// 			while(hashSet.count(currentNum + 1)){
// 				currentNum += 1;
// 				currentStreak += 1;
// 			}

// 			longestStreak = max(longestStreak, currentStreak);
// 		}
// 	}

// 	return longestStreak;
// }

//Time Complexity : O(N)
//Space Complexity : O(N)


