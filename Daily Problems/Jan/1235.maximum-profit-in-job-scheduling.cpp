/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start

class Job
{
public:
    int startTime;
    int endTime;
    int profit;
    Job(int startTime, int endTime, int profit)
    {
        this->startTime = startTime;
        this->endTime = endTime;
        this->profit = profit;
    }

    static bool compare(const Job &a, const Job &b)
    {
        return a.startTime < b.startTime;
    }
};

class Solution
{
public:
    int maxProfit(vector<Job> &jobs, int index, unordered_map<int, int> &memo)
    {
        if (index == jobs.size())
            return 0;

        if (memo.count(index))
            return memo[index];

        int left = index + 1;
        int right = jobs.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (jobs[index].endTime <= jobs[mid].startTime)
                right = mid;
            else
                left = mid + 1;
        }

        int res = 0;
        res = maxProfit(jobs, right, memo) + jobs[index].profit;
        res = max(res, maxProfit(jobs, index + 1, memo));

        memo[index] = res;
        return memo[index];
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        vector<Job> jobs;
        for (int i = 0; i < profit.size(); i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end(), Job::compare);

        unordered_map<int, int> memo;
        return maxProfit(jobs, 0, memo);
    }
};

int main()
{
    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};

    int maxProfit = Solution().jobScheduling(startTime, endTime, profit);

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
// @lc code=end
