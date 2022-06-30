#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lettersAndPositions;
        int longestSubstringSize = 0;
        
        int start = 0, end, pos;
        for (end = 0; end < s.size(); end++) {
            pos = lettersAndPositions.find(s[end]) == lettersAndPositions.end() ? -1 : lettersAndPositions[s[end]];
            if (pos >= start) { 
                longestSubstringSize = max(longestSubstringSize, end - start);
                start = pos + 1;
            }

            lettersAndPositions[s[end]] = end;
        }

        return longestSubstringSize = max(longestSubstringSize, end - start);
    }
};