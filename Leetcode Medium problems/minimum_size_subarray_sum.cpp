/*
Problem Statement Link: https://leetcode.com/problems/minimum-size-subarray-sum/

Problem Statement: Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.


Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1


Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104

*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int n = nums.size(), start = 0, end = 0;
      long int sum = 0;
      int minSize = INT_MAX;
      
      for(end = 0; end < n; end++) {
        sum += nums[end];
        
        // If sum becomes greater then the target we will move the start pointer by 1 & decrease the sum
        while(sum >= target && start < n) {
          // Update the minSize
          minSize = min(end - start + 1, minSize);

          // Remove the starting elements
          sum -= nums[start];
          start++;
        }
      }
      
      return minSize == INT_MAX ? 0 : minSize;    
    }
};
