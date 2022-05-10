//Q18 Count Reverse Pairs (493 leetcode HARD) 

//





//Approach 1 : Brute-Force Solution (nested loop)

int reversePairs(vector < int > & arr) {
  int Pairs = 0;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[i] > 2 * arr[j]) Pairs++;
    }
  }
  return Pairs;
}

//Time Complexity : O(N ^ 2)
//Space Complexity : O(1)


//Approach 2 : Optimal Approach (Using Merge Sort)

// Intuition:

// -> We will be using the Merge Sort Algorithm to solve this problem. We split the whole array into 2  parts creating a Merge Sort Tree-like structure. During the conquer step we do the following task : 

// -> We take the left half of the Array and Right half of the Array, both are sorted in themselves. 

// -> We will be checking the following condition arr[i] <= 2*arr[j]  where i is the pointer in the Left Array and j is the pointer in the Right Array. 

// -> If at any point arr[i] <= 2*arr[j] , we add 1  to the answer as this pair has a contribution to the answer. 

// -> If Left Array gets exhausted before Right Array we keep on adding the distance j pointer traveled as both the arrays are Sorted so the next ith element from Left Subarray will equally contribute to the answer.

// -> The moment when both Arrays get exhausted we perform a merge operation. This goes on until we get the original array as a Sorted array.

int Merge(vector <int> &nums, int low, int mid, int high){
        int total = 0;
    int i=low, j = mid+1;
    
    while(i<=mid && j<=high){
        while(i<=mid && nums[i]<=2ll*nums[j]) i++;
        
        total += mid-i+1;
        j++;
    }

 //    for(int i=low; i<=mid; i++){
	// 	while(j<=high && nums[i] > 2 LL * nums[j]){
	// 		j++;
	// 	}
	// 	total += (j - (mid+1));
	// }

    vector<int> t;
    int left = low, right = mid + 1;

      while (left <= mid && right <= high) {

        if (nums[left] <= nums[right]) {
          t.push_back(nums[left++]);
        } else {
          t.push_back(nums[right++]);
        }
      }

      while (left <= mid) {
        t.push_back(nums[left++]);
      }
      while (right <= high) {
        t.push_back(nums[right++]);
      }

      for (int i = low; i <= high; i++) {
        nums[i] = t[i - low];
      }
      return total;
}

int MergeSort(vector <int> &arr, int low, int high){
    if(low >= high) return 0;
    
    int mid = (low + high)/2;
    int inv = MergeSort(arr, low, mid);
    inv += MergeSort(arr, mid+1, high);
    inv += Merge(arr, low, mid, high);

    return inv;
}

int reversePairs(vector <int> &arr){
    return MergeSort(arr, 0, arr.size() - 1);
}



//Time Complexity : O(N * log(N)) + O(N) + O(N)
//Space Complexity : O(N)
