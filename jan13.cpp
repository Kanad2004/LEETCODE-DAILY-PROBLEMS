#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        unordered_map<char, int> charFrequencyMap;
        for (char c : s)
        {
            charFrequencyMap[c]++;
        }

        int deleteCount = 0;

        for (auto it : charFrequencyMap)
        {
            int frequency = it.second;
            if (frequency % 2 == 1)
            {
                deleteCount += frequency - 1;
            }
            else
            {
                deleteCount += frequency - 2;
            }
        }

        return s.length() - deleteCount;
    }
};

// Time Complexity : O(n) + O(26)
// Space Complexity : O(26)

// Approach 2
class Solution
{
public:
    int minimumLength(string s)
    {
        vector<int> charFrequencyMap(26, 0);
        int totalLength = 0;
        for (char c : s)
        {
            charFrequencyMap[c - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (charFrequencyMap[i] == 0)
            {
                continue;
            }
            else if (charFrequencyMap[i] % 2 == 0)
            {
                totalLength += 2;
            }
            else
            {
                totalLength += 1;
            }
        }

        return totalLength;
    }
};

// Same Time and space complexity but it uses vector instead of map which more time and memory as compared to map
