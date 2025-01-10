#include <bits/stdc++.h>
using namespace std;


//Approach 1

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // Iterate through each shift operation
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            // Apply the shift to each character in the range [start, end]
            for (int i = start; i <= end; ++i) {
                if (direction == 1) {
                    // Shift forward
                    s[i] = (s[i] - 'a' + 1) % 26 + 'a';
                } else {
                    // Shift backward
                    s[i] = (s[i] - 'a' - 1 + 26) % 26 + 'a';
                }
            }
        }
        
        return s;
    }
};


//Let n = s.length m = shitfs.size() k = average length of the ranges in shift
//Time Complexity : O(m * k) = O(m * n)
//Space Complexity : O(1)
//TLE


//Approach 2

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftEffect(n + 1, 0);

        // Accumulate shifts using a difference array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            // Add +1 for forward and -1 for backward
            shiftEffect[start] += (direction == 1 ? 1 : -1);
            shiftEffect[end + 1] -= (direction == 1 ? 1 : -1);
        }

        // Compute the net effect using prefix sums
        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += shiftEffect[i];
            // Normalize the shift to handle wrapping
            int normalizedShift = (cumulativeShift % 26 + 26) % 26;
            s[i] = (s[i] - 'a' + normalizedShift) % 26 + 'a';
        }

        return s;
    }
};


//Let m = number of shitfs n = length of string
//Time Complexity : O(m + n)
//Space Complexity : O(n)