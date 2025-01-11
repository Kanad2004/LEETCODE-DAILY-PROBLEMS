#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        // Step 1: If k > s.length(), it's impossible
        if (k > s.length())
            return false;

        // Step 2: Count character frequencies
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }

        // Step 3: Count odd frequencies
        int oddCount = 0;
        for (auto &entry : freq)
        {
            if (entry.second % 2 != 0)
            {
                oddCount++;
            }
        }

        // Step 4: Evaluate conditions
        // If oddCount > k, it's impossible
        if (oddCount > k)
            return false;

        // Otherwise, it's possible
        return true;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)

// Approach 2
class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        // Step 1: If k > s.length(), it's impossible
        if (k > s.length())
            return false;

        // Step 2: Count character frequencies using a fixed-size array
        int freq[26] = {0};
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        // Step 3: Count odd frequencies
        int oddCount = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 != 0)
            {
                oddCount++;
            }
        }

        // Step 4: Evaluate conditions
        return oddCount <= k;
    }
};

// Same time and space complexity
