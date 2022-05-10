//Q17 (62) Grid Unique Paths
// Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.
// Input Format: m = 2, n= 2
// Output: 2

//Approach 1 : Recursion
// The problem states that we can either move rightward or downward direction. So we recursively try out all the possible combinations.

int countPaths(int i,int j,int n,int m)
{
    if(i==(n-1)&&j==(m-1)) return 1;
    if(i>=n||j>=m) return 0;
    else return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
}
int uniquePaths(int m, int n) {
   return countPaths(0,0,m,n);
}

//Time Complexity : Exponential
//Space Complexity : Exponential due to Stack space


//Approach 2 : Dynamic Programming Solution

//Explained in video : https://takeuforward.org/data-structure/grid-unique-paths-count-paths-from-left-top-to-the-right-bottom-of-a-matrix/

int countPaths(int i, int j, int n, int m, vector<vector<int>> &dp){
	if(i==(n-1) && j==(m-1)) return 1;
	if(i>=n || j>=m) return 0;

	if(dp[i][j]!=-1) return dp[i][j];
	else return dp[i][j] = countPaths(i+1,j,n,m,dp) + countPaths(i,j+1,n,m,dp);
}
int uniquepaths(int n, int m){
	vector<vector<int>> dp(m+1, vector<int>(n+1,-1));

	int num = countPaths(0,0,n,m,dp);
	if(m==1 && n==1) return num; //imp step
	return dp[0][0];
}

//Time Complexity : O(N * M)
//Space Comlexity : O(N * M)



//Approach 3 : Combination (Maths Problem)

//All the unique paths can be calculated with a simple single formula which is (N+M-2) C (N-1) or (N+M-2) C (M-1).
//Intuition : If we observe examples there is a similarity in paths from start to end. Each time we are taking an exactly m+n-2 number of steps to reach the end.
// From start to reach the end we need a certain number of rightward directions and a certain number of downward directions. So we can figure out we need n-1 no. of rightward direction and m-1 no. of downward direction to reach the endpoint.
// Since we need an m+n-2 number of steps to reach the end among those steps if we choose n-1 rightward direction or m-1 downward direction and calculate the combinations ( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.



int uniquePaths(int m, int n) {
    int N = n + m - 2;
    int r = m - 1; 
    double res = 1;
    
    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}

//Time Complexity : O(N-1) or O(M-1)
//Space Complexity : O(1)


