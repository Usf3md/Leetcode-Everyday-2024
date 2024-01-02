/*
 * @lc app=leetcode id=2610 lang=cpp
 *
 * [2610] Convert an Array Into a 2D Array With Conditions
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> res;
        unordered_map<int, int> indexMap;
        for (int i = 0; i < nums.size(); i++)
            indexMap[nums[i]];

        for (int i = 0; i < nums.size(); i++)
        {
            if (res.size() <= indexMap[nums[i]])
                res.push_back(vector<int>());
            res[indexMap[nums[i]]++].push_back(nums[i]);
        }
        return res;
    }
};

int main()
{
    vector<int> v = {1, 3, 4, 1, 2, 3, 1};
    for (vector<int> v : Solution().findMatrix(v))
    {
        for (int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}

// @lc code=end
