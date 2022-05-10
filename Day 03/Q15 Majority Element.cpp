//Q14 (169) Find the Majority Element that occurs more than N/2 times in an array.
// Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.
// Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}
// Result: 2
// Explanation: After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.


// Approach 1 (Brute Force):

// Check the count of occurrences of all elements of the array one by one. Start from the first element of the array and count the number of times it occurs in the array. If the count is greater than the floor of N/2 then return that element as the answer. If not, proceed with the next element in the array and repeat the process.

// Time Complexity: O(N2) 
// Space Complexity: O(1)


// Approach 2 (Better):

// Intuition: Use a better data structure to reduce the number of look up operations and hence the time complexity. Moreover, we have been calculating the count of the same element again and again – so we have to reduce that also.

// Algorithm: 
// Use a hashmap and store as (key,value) pairs. (Can also use frequency array based on size of nums) 
// Here the key will be the element of the array and value will be the number of times it occurs. 
// Traverse the array and update the value of the key. Simultaneously check if the value is greater than floor of N/2. 
// If yes, return the key 
// Else iterate forward.

// Time Complexity: O(N)-> Frequency array or O(N log N) -> HashMap 
// Space Complexity: O(N)



//Approach 3: [Optimal] Moore's Voting Algorithm

// Intuition: The question clearly states that the nums array has a majority element. Since it has a majority element we can say definitely the count is more than N/2.

// Majority element count = N/2 + x;

// Minority/Other elements = N/2 – x;

// Where x is the number of times it occurs after reaching the minimum value N/2.

// Now, we can say that count of minority elements and majority element are equal upto certain point of time in the array. So when we traverse through the array we try to keep track of the count of elements and which element we are tracking. Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the majority element. 

// Algo: 

// Initialize 2 variables: 
// Count –  for tracking the count of element
// Element – for which element we are counting
// Traverse through nums array.
// If Count is 0 then initialize the current traversing integer of array as Element 
// If the traversing integer of array and Element are same increase Count by 1
// If they are different decrease Count by 1
// The integer present in Element is the result we are expecting 

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        if(num==candidate) count += 1; 
        else count -= 1; 
    }

    return candidate;
}

// Time Complexity : O(N)
//Space Complexity : O(1)

// Follow-up question you can try: Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

