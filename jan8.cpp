#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution
{
public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        // Helper function to check if str1 is both a prefix and a suffix of str2
        auto isPrefixAndSuffix = [](const string &str1, const string &str2) -> bool
        {
            if (str1.size() > str2.size())
                return false;
            return str2.substr(0, str1.size()) == str1 &&
                   str2.substr(str2.size() - str1.size()) == str1;
        };

        int count = 0; // To store the count of valid (i, j) pairs

        // Iterate through all possible pairs (i, j)
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                // Check if words[i] is both prefix and suffix of words[j]
                if (isPrefixAndSuffix(words[i], words[j]))
                {
                    count++;
                }
            }
        }

        return count;
    }
};

// m is maximum length of word
// Time Complexity : O(n ^ 2 * m)
// Space Complexity : O(1)

// Approach 2
class Solution
{
public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        unordered_map<string, int> prefixSuffixCount; // Store counts of potential prefixes/suffixes
        int count = 0;

        // Iterate through each word in the array
        for (const auto &word : words)
        {
            int len = word.size();

            // Check if this word can match any previously stored prefix-suffix patterns
            for (int i = 1; i <= len; ++i)
            {
                string prefix = word.substr(0, i);    // Extract prefix of length i
                string suffix = word.substr(len - i); // Extract suffix of length i

                if (prefix == suffix && prefixSuffixCount[prefix] > 0)
                {
                    count += prefixSuffixCount[prefix]; // Add the count of previous matches
                }
            }

            // Add this word to the prefixSuffixCount map
            prefixSuffixCount[word]++;
        }

        return count;
    }
};

// m is average length of word
// k is total number of unique prefixes or suffixes

// Time Complexity : O(n * m ^ 2)

// Space Complexity : O(k)