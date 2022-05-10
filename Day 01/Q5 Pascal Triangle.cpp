//Q5 (118) Pasacal Triangle

//The problem pascal's trianagle can be asked in many different ways like the can ask you :

//1. to calculate the value at specific row and column of a pascal triangle.

//the value at a specific row and column of a pascal triangle can be calculated by the formula (row - 1)C(col - 1)
// for example : value at row = 5 and col = 3 is equal to 4(C)2.
// which is equal to (4*3)/(2*1) = 6

//2. to calculate entire row of a pascal triangle.
// We can calculate the value of (row - 1)C(col - 1) for each place of the row but it will be a expensive operation. Hence we can do this in O(N) Time Complexity using :

// Intuition : https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=9 at (4:00)

for(int i=0; i<k; ++i){
	res*=(n-i);
	res/=(i+1);
	arr.push_back(res);
}

//3. to calculate the whole pascal triangle.

// Intuition : https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=9N


vector<vector<int>> generate(int numRows) {
    vector<vector<int>> r(numRows);

    for (int i = 0; i < numRows; i++) {
        r[i].resize(i + 1);
        r[i][0] = r[i][i] = 1;

        for (int j = 1; j < i; j++)
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    }
    
    return r;
}

//Time Complexity : O(numRows ^ 2)
//Space Complexity : O(numRows ^ 2)
