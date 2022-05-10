// Q9 Merge two sorted arrays without extra space

//Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Input: 
// n = 4, arr1[] = [1 4 8 10] 
// m = 5, arr2[] = [2 3 9]

// Output: 
// arr1[] = [1 2 3 4]
// arr2[] = [8 9 10]

// Explanation:After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.


//Approach 1 : Brute Force 

// Intuition: We can use a new array of size n+m and put all elements of arr1 and arr2 in it, and sort it. After sorting it, but all the elements in arr1 and arr2.

// Steps:

// Make an arr3 of size n+m.
// Put elements arr1 and arr2 in arr3.
// Sort the arr3.
// Now first fill the arr1 and then fill remaining elements in arr2. 

void merge(int arr1[], int arr2[], int n, int m) {
    int arr3[n+m];
    int k = 0;
    for (int i = 0; i < n; i++) {
      arr3[k++] = arr1[i];
    }
    for (int i = 0; i < m; i++) {
      arr3[k++] = arr2[i];
    }
    sort(arr3,arr3+m+n);
    k = 0;
    for (int i = 0; i < n; i++) {
      arr1[i] = arr3[k++];
    }
    for (int i = 0; i < m; i++) {
      arr2[i] = arr3[k++];
    }

}

// Time complexity: O(n*log(n))+O(n)+O(n)
// Space Complexity: O(n) 


//Approach 2: Without using extra space.

// Intuition: We can think of Iterating in arr1 and whenever we encounter an element that is greater than the first element of arr2, just swap it. Now rearrange the arr2 in a sorted manner, after completion of the loop we will get elements of both the arrays in non-decreasing order.

// Steps:

// 1. Use a for loop in arr1.
// 2. Whenever we get any element in arr1 which is greater than the first element of arr2,swap it.
// 3. Rearrange arr2.
// 4. Repeat the process.

void merge(int arr1[], int arr2[], int n, int m) {
  // code here
  int i, k;
  for (i = 0; i < n; i++) {
    // take first element from arr1 
    // compare it with first element of second array
    // if condition match, then swap
    if (arr1[i] > arr2[0]) {
      int temp = arr1[i];
      arr1[i] = arr2[0];
      arr2[0] = temp;
    }

    // then sort the second array
    // put the element in its correct position
    // so that next cycle can swap elements correctly
    int first = arr2[0];
    // insertion sort is used here
    for (k = 1; k < m && arr2[k] < first; k++) {
      arr2[k - 1] = arr2[k];
    }
    arr2[k - 1] = first;
  }
}

// Time complexity: O(n*m)
// Space Complexity: O(1) 

//Approach 3 : Gap Method
