#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        unordered_map<int, int> numsIds;

        for (int i = 0; i < nums.size(); i++) {
            if (numsIds.find(target - nums[i]) != numsIds.end()) {
                sol.push_back(numsIds[target - nums[i]]);
                sol.push_back(i);
                return sol;
            } else {
                numsIds[nums[i]] = i;
            }
        }

        return sol;
    }
};