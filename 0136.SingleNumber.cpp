/*
************************************************************ 136. Single Number ************************************************************


Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: 
nums = [1]
Output: 1
 
Constraints:
1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

SOLUTION----->>>

Intuition:
Step 1: Create a Hash table of the length (max value - min value) of nums vector.
Step 2: Using the value of each element of nums as a index value of the hash table. If at that location the value was 0 then add 1 else subtract 1.
Step 3: Check the hash table with value 1 as it has occured only once in the given vector nums. So get the index of the value 1 in the hash table and by adjusting with min value, return the actual element value that is only single number in nums. Hence the problem names Single Number.

Approach:
Solved using SIMPLE for loop with if else statement.

Complexity:
Time complexity: O(n)O(n)O(n)
Beats almost 80% submissions in Runtime.

Code  */
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
           
        int s1=nums.size();   // get the size of the nums vector

        auto it = minmax_element(nums.begin(), nums.end()); // find minimum and maximum value from the given vector
        int mini = *it.first;   // store the minimum value in mini
        int maxi = *it.second;  // store the maximum value in maxi
        int len = maxi-mini+1;  // calculate the size of a hash table
  
        vector<int> store(len,0);  // defining a hash table of size len and initializing all elements as 0
  
        for(int i=0; i<s1; i++)
        {
            if(store[nums[i]-mini]==0)
                store[nums[i]-mini] += 1;   // add 1 if the value at store[nums[i]-mini]=0
            else
                store[nums[i]-mini] -= 1;   // else subtract 1 as the value has occured more than once 
        }
	    
        auto it2 = minmax_element(store.begin(), store.end());  // find minimum and maximum value of the hash table

        int max_indx = distance(store.begin(), it2.second);  // get the index value of the single occured number in the hash table
	   
        return max_indx+mini;  // returing by adjusting the index to the actual element value in nums element
    }
};
