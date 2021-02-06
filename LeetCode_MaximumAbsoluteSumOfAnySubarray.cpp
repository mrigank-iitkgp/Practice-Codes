/*
Problem Link : https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray*/

#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <set>
#include <string> 
#include <vector>
#include <algorithm>
#include <numeric>
 
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int preSum = 0;
        int mx = 0 , mn = 0;
        for(auto num : nums)
        {
            preSum += num;
            mx = max(mx , preSum);
            mn = min(mn , preSum);
        }
        return mx - mn;
    }
};