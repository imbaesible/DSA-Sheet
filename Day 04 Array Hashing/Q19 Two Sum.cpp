//Q19 Two Sum (1)

//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

//Input: nums = [2, 7, 11, 15], target = 9
//Output: [0, 1]

//Approach 1: using Loop (Brute Force)

for (int i = 0; i < nums.size(); ++i) {
	 for (int j = i + 1; j < nums.size(); ++j) {
		 if (nums[i] + nums[j] == target) {
			 res.emplace_back(i);
			 res.emplace_back(j);
			 break;
		 }
	 }
	 if (res.size() == 2)
		 break;
}
return res;

//Time Complexity : O(N ^ 2)
//Space Complexity : O(1)


//Approach 2 : Two-Pointer Approach

// Intuition: Think about, what if the array is sorted? If the array is sorted, is it possible to reach a sum by traversing the array from both sides simultaneously?

// We sort the array, use two variables, each will start from one end of the array, and traverse in both directions till we get the required sum.

vector<int> twoSum(vector<int>& nums, int target) {

	vector<int> res,store;
	store = nums;

	sort(store.begin(), store.end());

	int left=0,right=nums.size()-1;
	int n1,n2;

	while(left<right){
    	if(store[left]+store[right]==target){

        	n1 = store[left];
        	n2 = store[right];

        	break;

    	}
    	else if(store[left]+store[right]>target)
        	    right--;
    	else
        	    left++;
	}

	for(int i=0;i<nums.size();++i){

    	if(nums[i]==n1)
        	    res.emplace_back(i);
    	else if(nums[i]==n2)
        	    res.emplace_back(i);
	}

	    return res;
}

//Time Complexity : O(N * log(N))
//Space Complexity : O(1)



//Approach 3 : [Optimal] Hashing

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mpp;
    vector <int> ans;
    
    for(int i=0; i<=nums.size(); i++){
        if(mpp.find(target-nums[i]) != mpp.end()){
            ans.push_back(mpp[target-nums[i]]);
            ans.push_back(i);
            return ans;
        }else{
            mpp[nums[i]]=i;
        }
    }
    
    return ans;
}

//Time Complexity : O(N) (at many number of collisions it can be N^2)
//Space Complexity : O(N)




