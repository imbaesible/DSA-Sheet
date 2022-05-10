// Q2. Sort an array of 0's 1's and 2's



// Approach 1: Sorting

// Sorting ( even if it is not the expected solution here but it can be considered as one of the approach ). Since the array contains only 3 integers, 0, 1, and 2. Simply sorting the array would arrange the elements in increasing order.

// Time Complexity: O(N*logN)
// Space Complexity: O(1)




// Approach 2 : Brute-Force (Keeping count of values)

// Intuition: Since in this case there are only 3 distinct values in the array so it’s easy to maintain the count of all, Like the count of 0, 1, and 2. This can be followed by overwriting the array based on the frequency(count) of the values.

// Algo: 

// 1. Take 3 variables to maintain the count of 0, 1 and 2.
// 2. Travel the array once and increment the corresponding counting variables
	// ( let’s consider count_0 = a, count_1 = b, count_2 = c )

// 3. In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in array with ’0’, the next ‘b’ with ‘1’ and the remaining ‘c’ with ‘2’.

// Time Complexity: O(N) + O(N)
// Space Complexity: O(1)


// Approach 3 : 3-Pointer approach
// Imp :: This problem is a variation of the popular Dutch National flag algorithm 


// Intuition: In this approach, we will be using 3 pointers named low, mid, and high. We will be using these 3 pointers to move around the values. The primary goal here is to move 0s to the left and 2s to the right of the array and at the same time all the 1s shall be in the middle region of the array and hence the array will be sorted. 

void sortColors(vector<int>& nums) {
    int lo = 0; 
    int hi = nums.size() - 1; 
    int mid = 0; 

    while (mid <= hi) { 
        switch (nums[mid]) { 

        // If the element is 0 
        case 0: 
            swap(nums[lo++], nums[mid++]); 
            break; 

        // If the element is 1 . 
        case 1: 
            mid++; 
            break; 

        // If the element is 2 
        case 2: 
            swap(nums[mid], nums[hi--]); 
            break; 
        }
    }    
}

// Time Complexity: O(N)
// Space Complexity: O(1)