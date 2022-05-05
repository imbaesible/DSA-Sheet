// Q4 (31) Next Permutation

//Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.
// Input: nums = [1,2,3]
// Output: [1,3,2]



//Approach 1: Brute Force: Finding all possible permutations. 

// Step 1: Find all possible permutations of elements present and store them.
// Step 2: Search input from all possible permutations.
// Step 3: Print the next permutation present right after it.

// Time Complexity : O(N! x N)
// Space Complexity : O(1)



//Approach 2 : C++ Built in function

int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}



//Approach 3: Optimal approach

// Intuition lies behind the lexicographical ordering of all possible permutations of a given array. There will always be an increasing sequence of all possible permutations when observed.

// Step 1: Linearly traverse array from backward such that ith index value of the array is less than (i+1)th index value. Store that index in a variable.

// Step 2: If the index value received from step 1 is less than 0. This means the given input array is the largest lexicographical permutation. Hence, we will reverse the input array to get the minimum or starting permutation. Linearly traverse array from backward. Find an index that has a value greater than the previously found index. Store index another variable.

// Step 3: Swap values present in indices found in the above two steps.

// Step 4: Reverse array from index+1 where the index is found at step 1 till the end of the array.


//1. ind 1 = arr[i] < arr[i+1]
//2. ind 2 = arr[i] > arr[ind 1]
//3. swap(arr[ind 1], arr[ind 2])
//4. reverse(ind1 + 1, last)

void nextPermutation(vector<int>& nums) {
    int n=nums.size(),k,l;
    for(k=n-2;k>=0;k--){
        if(nums[k]<nums[k+1]){
            break;
        }
    }
    if(k<0){
        reverse(nums.begin(),nums.end());
    }else{
        for(l=n-1;l>k;l--){
            if(nums[l]>nums[k]){
                break;
            }
        }
        swap(nums[l],nums[k]);
        reverse(nums.begin()+k+1,nums.end());
        
    }
    
}





