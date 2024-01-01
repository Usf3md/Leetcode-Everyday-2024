/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;
        while (true)
        {
            if (i == g.size() || j == s.size())
                break;

            if (g[i] <= s[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }

        return i;
    }
};
// @lc code=end
