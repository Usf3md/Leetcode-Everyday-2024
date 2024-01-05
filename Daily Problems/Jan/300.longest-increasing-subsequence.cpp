/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int lis(vector<int> &nums, unordered_map<int, int> &memo, int index)
    {
        if (memo.count(index))
            return memo[index];

        int maxLen = 0;
        for (int i = index; i < nums.size() - 1; i++)
        {
            if (nums[index] >= nums[i + 1])
                continue;
            maxLen = max(maxLen, lis(nums, memo, i + 1));
        }

        memo[index] = maxLen + 1;
        return memo[index];
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
            mx = max(mx, lis(nums, m, i));
        return mx;
    }
};

int main()
{
    vector<int> nums = {4, 10, 4, 3, 8, 9};
    std::cout << Solution().lengthOfLIS(nums);
    return 0;
}
// @lc code=end
