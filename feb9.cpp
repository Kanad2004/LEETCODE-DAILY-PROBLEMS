class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        long long totalPairs = ((long long)(n - 1) * n) / 2;
        // cout << "totalPairs = " << totalPairs << endl;
        long long goodPairs = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[nums[i] - i]++;
        }

        for (auto it : m)
        {
            // cout << "key = " << it.first << endl;
            // cout << "value = " << it.second << endl;
            long long count = it.second;
            long long pairs = (count * (count - 1)) / 2;
            // cout << "pairs = " << pairs << endl;
            goodPairs += pairs;
            // cout << "goodPairs = " << goodPairs << endl;
        }

        // cout << "goodPairs = " << goodPairs << endl;
        return totalPairs - goodPairs;
    }
};
