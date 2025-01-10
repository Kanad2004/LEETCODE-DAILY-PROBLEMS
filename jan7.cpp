#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> result;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (i != j && words[j].find(words[i]) != string::npos)
                { // Check if words[i] is a substring of words[j]
                    result.push_back(words[i]);
                    break; // Avoid duplicate entries in the result
                }
            }
        }
        return result;
    }
};

// m is the average length of a word
// k is the number of strings added to

// Time Complexity : O(n^2 *m)
// Space Complexity : O(k)

// Approach 2
class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        // Sort words by length
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });

        vector<string> result;

        // Check if each word is a substring of any longer word
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (words[j].find(words[i]) != string::npos)
                {
                    result.push_back(words[i]);
                    break; // Avoid duplicates
                }
            }
        }

        return result;
    }
};

// Time Complexity : o(nlogn + n^2 * m)
// Space Complexity : O(1)

// Approach 3
class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        // Create a concatenated string with delimiters
        string superString = "";
        for (const string &word : words)
        {
            superString += word + " ";
        }

        vector<string> result;

        // Check if each word appears more than once in the superString
        for (const string &word : words)
        {
            if (superString.find(word) != superString.rfind(word))
            { // Appears more than once
                result.push_back(word);
            }
        }

        return result;
    }
};

// Time Complexity : O(n.m)
// Space Complexity : O(n * m);