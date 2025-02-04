#include <bits/stdc++.h>
using namespace std;

//! Best Approach
class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int maxAns = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                ans += nums[i];
            }
            else
            {
                maxAns = max(maxAns, ans);
                ans = nums[i];
            }
        }

        maxAns = max(maxAns, ans);

        return maxAns;
    }
};

//! Time Complexity : O(N)
//! Space Complexity : O(1)