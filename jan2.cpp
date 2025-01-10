#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        // Define vowels
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();

        // Precompute prefix sum for strings starting and ending with vowels
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            char first = words[i][0];
            char last = words[i][words[i].length() - 1];
            if (vowels.count(first) && vowels.count(last))
            {
                prefixSum[i + 1] = prefixSum[i] + 1;
            }
            else
            {
                prefixSum[i + 1] = prefixSum[i];
            }
        }

        // Answer queries using prefix sum
        vector<int> ans;
        for (auto &query : queries)
        {
            int li = query[0];
            int ri = query[1];
            ans.push_back(prefixSum[ri + 1] - prefixSum[li]);
        }

        return ans;
    }
};
