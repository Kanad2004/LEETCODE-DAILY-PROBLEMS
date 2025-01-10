#include <bits/stdc++.h>
using namespace std;

class Solution
{
    auto getFrequency(string word)
    {
        unordered_map<char, int> freq;
        for (char c : word)
        {
            freq[c]++;
        }
        return freq;
    }

public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> result;
        for (auto word1 : words1)
        {
            unordered_map<char, int> freq1 = getFrequency(word1);
            bool isUniversal = true;

            for (auto word2 : words2)
            {
                unordered_map<char, int> freq2 = getFrequency(word2);
                for (auto [ch, count] : freq2)
                {
                    if (freq1[ch] < count)
                    {
                        isUniversal = false;
                        break;
                    }
                }
                if (!isUniversal)
                    break;
            }

            if (isUniversal)
            {
                result.push_back(word1);
            }
        }

        return result;
    }
};

// n - length of words1
// m - length of words2
// k - average length of strings

// Time Complexity : O(n * m * k)
// Space Complexity : O(k)

// Gives TLE

// Approach 2