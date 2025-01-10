#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        int ans = 0;
        long long prefixSum = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            prefixSum += nums[i];
            long long temp = sum - prefixSum;
            if (prefixSum >= temp)
            {
                ans++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {10, 4, -8, 7};
    cout << obj.waysToSplitArray(nums) << endl;
    return 0;
}