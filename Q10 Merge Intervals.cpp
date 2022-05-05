// Q10 Merge Overlapping Sub-Intervals

// Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.
// Input: intervals=[[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6] intervals.

// Approach 1 : Brute Force

// First check whether the array is sorted or not.If not sort the array. Now linearly iterate over the array and then check for all of its next intervals whether they are overlapping with the interval at the current index. Take a new data structure and insert the overlapped interval. If while iterating if the interval lies in the interval present in the data structure simply continue and move to the next interval.

vector < pair < int, int >> merge(vector < pair < int, int >> & arr) {

  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector < pair < int, int >> ans;

  for (int i = 0; i < n; i++) {
    int start = arr[i].first, end = arr[i].second;

    //since the intervals already lies 
    //in the data structure present we continue
    if (!ans.empty()) {
      if (start <= ans.back().second) {
        continue;
      }
    }

    for (int j = i + 1; j < n; j++) {
      if (arr[j].first <= end) {
        end = arr[j].second;
      }
    }

    ans.push_back({
      start,
      end
    });
  }

  return ans;
}

// Time Complexity: O(NlogN)+O(N*N). O(NlogN) for sorting the array, and O(N*N) because we are checking to the right for each index which is a nested loop.
// Space Complexity: O(N), as we are using a separate data structure.


