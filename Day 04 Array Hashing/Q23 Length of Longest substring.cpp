//Q23 Length of Longest Substring without any Repeating Character (3)

// Given a string s, find the length of the longest substring without repeating characters.
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.



//Approach 1 : Brute force approach 

//This approach consists of taking the two loops one for traversing the string and another loop – nested loop for finding different substrings and after that, we will check for all substrings one by one and check for each and every element if the element is not found then we will store that element in HashSet otherwise we will break from the loop and count it.

int solve(string str) {
  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(str[j]);
    }
  }
  return maxans;
}

//Time Complexity : O(N ^ 2)
//Space Complexity : O(N)




//Approach 2 : Optimised Approach 1

//We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point of substring while ‘right’ will maintain the endpoint of the substring.’ right’ pointer will move forward and check for the duplicate occurrence of the current element if found then ‘left’ pointer will be shifted ahead so as to delete the duplicate elements.

int solve(string str) {
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}

// Time Complexity : O(2*N)
// Space Complexity : O(N)




// Approach 3 : More Optimised Approach

//In this approach, we will make a map that will take care of counting the elements and maintaining the frequency of each and every element as a unity by taking the latest index of every element.

int lengthofLongestSubstring(string s) {
  vector < int > mpp(256, -1);

  int left = 0, right = 0;
  int n = s.size();
  int len = 0;
  while (right < n) {
    if (mpp[s[right]] != -1)
      left = max(mpp[s[right]] + 1, left);

    mpp[s[right]] = right;

    len = max(len, right - left + 1);
    right++;
  }
  return len;
}

//Time Complexity : O(N)
//Space Complexity : O(N)




