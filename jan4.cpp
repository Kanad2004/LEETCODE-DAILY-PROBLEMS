#include <bits/stdc++.h>
using namespace std;


// Approach 1 :

#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        unordered_set<string> uniquePalindromes;
        int n = s.size();

        // Iterate through all triplets
        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    // Check if it's a palindrome
                    if (s[i] == s[k])
                    {
                        string palindrome = {s[i], s[j], s[k]};
                        uniquePalindromes.insert(palindrome);
                    }
                }
            }
        }

        return uniquePalindromes.size();
    }
};

// Time Complexity: O(n^3)
// Space Complexity: O(number of unique palindromes)
//Gives TLE

//Approach 2
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> left(26, 0), right(26, 0);
        unordered_set<string> uniquePalindromes;

        // Count frequencies of all characters in the suffix
        for (char c : s) {
            right[c - 'a']++;
        }

        // Iterate through the string
        for (int i = 0; i < n; ++i) {
            // Current character
            char current = s[i];
            // Remove it from the suffix
            right[current - 'a']--;

            // Check for palindromes with this character as the middle character
            for (int j = 0; j < 26; ++j) {
                if (left[j] > 0 && right[j] > 0) {
                    string palindrome = string(1, 'a' + j) + current + string(1, 'a' + j);
                    uniquePalindromes.insert(palindrome);
                }
            }

            // Add the current character to the prefix
            left[current - 'a']++;
        }

        return uniquePalindromes.size();
    }
};

// Time Complexity: O(n * 26)
// Space Complexity: O(2 * 26) + O(unique palindromes)

