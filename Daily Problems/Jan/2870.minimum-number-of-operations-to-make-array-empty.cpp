/*
 * @lc app=leetcode id=2870 lang=cpp
 *
 * [2870] Minimum Number of Operations to Make Array Empty
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (const int &num : nums)
            m[num]++;

        int second;
        int operations = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            second = it->second;
            if (it->second < 2)
                return -1;

            operations += it->second / 3;
            if (it->second % 3)
                operations++;
        }
        return operations;
    }
};
// @lc code=end
