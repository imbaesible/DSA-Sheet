//Q13 (74 leetcode) Search in a sorted 2D matrix

// Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

// Given matrix has the following properties:

// 1. Integers in each row are sorted from left to right.
// 2. The first integer of each row is greater than the last integer of the previous row

// Approach 1: Naive Approach
// We can do a linear search on the whole matrix and search for our target element 
//Time Complexity : O(N x M)
//Space Complexity : O(1)


//Approach 2 : [Efficient] Bineary Search on whole matrix

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int lo = 0;
    if(!matrix.size()) return false;
    int hi = (matrix.size() * matrix[0].size()) - 1;
    
    while(lo <= hi) {
        int mid = (lo + (hi - lo) / 2);
        if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] == target) {
            return true;
        }
        if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] < target) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return false;
}

// Time complexity: O(log(m*n))
// Space complexity: O(1)


//Other Approach : Bineary Seach on each row
//Time Complexity : O(N x log(M))
//Space Comlexity : O(1)

//Other Approach : efficient for GFG problem
//Explained in video
int i = 0, j = m-1;
while(i<n && j>=0){
	if(mat[i][j] == x){
		return true;
	}
	if(mat[i][j] > x) j--; //moves down
	else i++; //moves left
}