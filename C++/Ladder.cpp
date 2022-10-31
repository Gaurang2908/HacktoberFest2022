/*

Suppose there is a ladder with n steps.  A person standing at the  bottom of the  ladder and  wants to 
reach to its top. Assume the person can take a jump of size 1 to k at a time. Then, count the number 
of ways, the person can reach the top of the ladder.

Example 
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1], 
	              [1, 1, 2], 
	              [1, 2, 1], 
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/
#include<iostream>
#include<vector>

using namespace std;

int numOfWays(int n, int k) {
	// base case
	if(n == 0) return 1;

	int count = 0;
	for(int j=1; j<=k; j++) {
		if(n-j >= 0) {
			count += numOfWays(n-j, k);
		}
	}

	return count;
}

int numOfWaysTopDown(int n, int k, vector<int>& dp) {
	// base case
	if(n == 0) return dp[n] = 1;

	// lookup
	if(dp[n] != -1) return dp[n];

	// recursive case
	int count = 0;
	for(int j=1; j<=k; j++) {
		if(n-j >= 0) {
			count += numOfWaysTopDown(n-j, k, dp);
		}
	}

	return dp[n] = count;
}

int numOfWaysBottomUp(int n, int k) {
	vector<int> dp(n+1, -1);
	dp[0] = 1;
	for(int i=1; i<=n; i++) {
		int count = 0;
		for(int j=1; j<=k; j++) {
			if(i-j >= 0) {
				count += dp[i-j];
			}
		}
		dp[i] = count;
	}
	return dp[n];
}

int numOfWaysBottomUpOptimised(int n, int k) {
	vector<int> dp(n+1, -1);
	dp[0] = 1;
	dp[1] = dp[0];

	for(int i=2; i<=k; i++) {
		dp[i] = 2*dp[i-1];
	}

	for(int i=k+1; i<=n; i++) {
		dp[i] = 2*dp[i-1] - dp[i-k-1];
	}

	return dp[n];
}

int main() {

	int n = 4;
	int k = 3;
	
	cout << numOfWays(n, k) << endl;

	vector<int> dp(n+1, -1);
	cout << numOfWaysTopDown(n, k, dp) << endl;
	cout << numOfWaysBottomUp(n, k) << endl;
	cout << numOfWaysBottomUpOptimised(n, k) << endl;

	return 0;
}


