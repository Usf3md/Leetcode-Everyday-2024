/*
 * @lc app=leetcode id=2125 lang=cpp
 *
 * [2125] Number of Laser Beams in a Bank
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int beams = 0;
        int topLasers = 0;
        int bottomLasers = 0;
        for (string &row : bank)
        {
            if (topLasers == 0)
                for (char &laser : row)
                    topLasers += laser - '0';
            else
            {
                for (char &laser : row)
                    bottomLasers += laser - '0';

                beams += topLasers * bottomLasers;
                if (bottomLasers != 0)
                    topLasers = bottomLasers;
                bottomLasers = 0;
            }
        }
        return beams;
    }
};
// @lc code=end
