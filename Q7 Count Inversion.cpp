// Q7 Count Inversion

//Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

// What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

// Input Format: N = 5, array[] = {5,3,2,1,4}
// Result: 8
// Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),
// (3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and 
// (1,4) as both are not satisfy our condition. 



// Approach 1: Brute Force Solution

// In this solution we'll use nested loop where i will point one index of array and j will traverse through array looking for inversion.

{
	int countInversion = 0;

	for(int i = 0; i< arr.size(); i++){
		for(int j=i; j<arr.size(); j++){
			if(arr[i] > arr[j]) countInversion++;
		}
	}

	return countInversion;
}

//Time Complexity : O(N ^ 2)
// Space Complexity : O(1)


//Approach 2: Using Merge Sort

//To sort the array, we will use mergeSort. In mergeSort, we will deep in one element, compare two elements, and put it in a new array in sorted order. By doing this for log(N) time, we will get the sorted array, and while comparing the two array elements 
//We will add some more lines of code such that it will count the inversion of the smaller array and slowly it will count for larger and larger array.



#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int temp[],int left,int mid,int right)
{
    int inv_count=0;
    int i = left;
    int j = mid;
    int k = left;
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

int merge_Sort(int arr[],int temp[],int left,int right)
{
    int mid,inv_count = 0;
    if(right > left)
    {
        mid = (left + right)/2;

        inv_count += merge_Sort(arr,temp,left,mid);
        inv_count += merge_Sort(arr,temp,mid+1,right);

        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

int main()
{
    int arr[]={5,3,2,1,4};
    int n=5;
    int temp[n];
    int ans = merge_Sort(arr,temp,0,n-1);
    cout<<"The total inversions are "<<ans<<endl; 


    return 0;
}
