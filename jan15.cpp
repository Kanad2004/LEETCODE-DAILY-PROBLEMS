#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        // Initialize result to num1. We will modify result.
        int result = num1;

        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = __builtin_popcount(result);

        // Start with the least significant bit (bit 0).
        int currentBit = 0;

        // Add bits to result if it has fewer set bits than the target.
        while (setBitsCount < targetSetBitsCount)
        {
            // If the current bit in result is not set (0), set it to 1.
            if (!isSet(result, currentBit))
            {
                setBit(result, currentBit);
                setBitsCount++;
            }
            // Move to the next bit.
            currentBit++;
        }

        // Remove bits from result if it has more set bits than the target.
        while (setBitsCount > targetSetBitsCount)
        {
            // If the current bit in result is set (1), unset it (make it 0).
            if (isSet(result, currentBit))
            {
                unsetBit(result, currentBit);
                setBitsCount--;
            }
            // Move to the next bit.
            currentBit++;
        }

        return result;
    }

private:
    // Helper function to check if the given bit position in x is set (1).
    bool isSet(int x, int bit) { return x & (1 << bit); }

    // Helper function to set the given bit position in x to 1.
    void setBit(int &x, int bit) { x |= (1 << bit); }

    // Helper function to unset the given bit position in x (set it to 0).
    void unsetBit(int &x, int bit) { x &= ~(1 << bit); }
};

// Time Complexity : O(logn)
// Space Complexity : O(1)

// Approach 2
class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int result = 0;

        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = 0;
        int currentBit = 31; // Start from the most significant bit.

        // While x has fewer set bits than num2
        while (setBitsCount < targetSetBitsCount)
        {
            // If the current bit of num1 is set or we must set all remaining
            // bits in result
            if (isSet(num1, currentBit) ||
                (targetSetBitsCount - setBitsCount > currentBit))
            {
                setBit(result, currentBit);
                setBitsCount++;
            }
            currentBit--; // Move to the next bit.
        }

        return result;
    }

private:
    // Helper function to check if the given bit position in x is set (1).
    bool isSet(int x, int bit) { return x & (1 << bit); }

    // Helper function to set the given bit position in x to 1.
    void setBit(int &x, int bit) { x |= (1 << bit); }
};

// Same space and time complexity