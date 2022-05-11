//Q20 Four Sum (18)

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 1. 0 <= a, b, c, d < n
// 2. a, b, c, and d are distinct.
// 3. nums[a] + nums[b] + nums[c] + nums[d] == target
// 4. You may return the answer in any order.

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


//Approach 1 : Using 3 pointers and Binary Search


vector<vector<int>> fourSum(vector<int> &nums, int target){
	int n = nums.size();
	sort(nums.begin(), nums.end());

	set<vecotr<int>> sv;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int k=j+1; k<n; k++){
				int x = (long long)target - (long long) nums[i] - (long long) nums[j] - (long long) nums[k];

				if(binary_search(nums.begin()+k+1, nums.end(), x)){
					vector<int> v;
					v.push_back(nums[i]);
					v.push_back(nums[j]);
					v.push_back(nums[k]);
					v.push_back(x);

					sort(v.begin(), v.end());
					sv.insert(v);
				}
			}
		}
	}

	vector<vector<int>> res(sv.begin(), sv.end());
	return res;
}

//Time Complexity : O(N*logN + N^3 * logN);
//Space Complexity : O(1)


//Approach 2 : Optimized Approach

//Intuition: In the previous approach we fixed three-pointers and did a binary search to find the fourth. Over here we will fix two-pointers and then find the remaining two elements using two pointer technique as the array will be sorted at first.


vector<vector<int>> fourSum(vector<int> &num, int target){
	vector<vector<int>> res;

	if(num.empty()) return res;
	int n = num.size();

	sort(num.begin(), num.end());

	for(int i=0; i<n; i++){
		int target_3 = target - num[i];

		for(int j=i+1; j<n; j++){
			int target_2 = target_3-num[j];

			int front = j+1;
			int back = n-1;

			while(front < back){
				int two_sum = num[front] + num[back];

				if(two_sum < target_2) front++;
				else if(two_sum > target_2) back--;
				else{
					vector<int> quadruplet(4, 0);
					quadruplet[0] = num[i];
					quadruplet[1] = num[j];
					quadruplet[2] = num[front];
					quadruplet[3] = num[back];
					res.push_back(quadruplet);


					while(front < back && num[front] == quadruplet[2]) ++front;
					while(front < back && num[back] == quadruplet[3]) --back;
				}
			}

			while( j+1 < n && num[j+1] == num[j]) ++j;

		}

		while(i+1 < n && num[i+1] == num[i]) ++i;
	}

	return res;
}


//Time Complexity : O(N ^ 3)
//Space Complexity : O(1)

