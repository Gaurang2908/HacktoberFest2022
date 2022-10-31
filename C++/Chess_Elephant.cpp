/*

Given a m x n chess board, count the number of ways a chess elephant can move from (0, 0)
to (x, y) such that it can only move in either the right or down direction at a time.

Example 
	Input : m = 2, n = 2, x = 1, y = 1
	Output: 2

	Input : m = 2, n = 3, x = 1, y = 2
	Output: 5
	
	Input : m = 3, n = 3, x = 2, y = 2
	Output: 14
	
	Input : m = 4, n = 4, x = 3, y = 3
	Output: 106

*/

#include<iostream>
#include<vector>

using namespace std;

int chessElephant(int i, int j) {
	// base case
	if(i == 0 && j == 0) return 1;

	// recursive case
	int count =  0;
	for(int k=0; k<i; k++) {
		count += chessElephant(k, j);
	}

	for(int k=0; k<j; k++) {
		count += chessElephant(i, k);
	}

	return count;
}

int chessElephantTopDown(int i, int j, vector<vector<int>>& dp) {
	// base case
	if(i == 0 && j == 0) return dp[i][j] = 1;

	// lookup
	if(dp[i][j] != -1) return dp[i][j];

	// recursive case
	int count =  0;
	for(int k=0; k<i; k++) {
		count += chessElephantTopDown(k, j, dp);
	}

	for(int k=0; k<j; k++) {
		count += chessElephantTopDown(i, k, dp);
	}

	return dp[i][j] = count;
}

int chessElephantBottomUp(int m, int n, int x, int y) {
	vector<vector<int>> dp(m, vector<int>(n));

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(i == 0 && j == 0) dp[0][0] = 1;
			else {
				int count =  0;	
				// you can reach the (i, j)th cell from either top or left
				// unless either i == 0 or j == 0 which are automatically 
				// handled by the loop conditions.
				for(int k=0; k<i; k++) {
					count += dp[k][j];
				}

				for(int k=0; k<j; k++) {
					count += dp[i][k];
				}
				dp[i][j] = count;
			}
		}
	}

	return dp[x][y];
}

int main() {

	int m = 3;
	int n = 3;

	int x = 0;
	int y = 2;

	cout << chessElephant(x, y) << endl;

	vector<vector<int>> dp(m, vector<int>(n, -1));
	cout << chessElephantTopDown(x, y, dp) << endl;
	cout << chessElephantBottomUp(m, n, x, y) << endl;

	return 0;
}
