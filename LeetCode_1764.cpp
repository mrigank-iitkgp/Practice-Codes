/* Author: Mrigank
Science is what we understand well enough to explain to a computer, 
    Art is everything else we do - Donald E. Knuth */

/*
Problem Link : https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/   */

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
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) 
    {
        auto itr = nums.begin();
        for(auto& group : groups)
        {
            itr = search(itr , nums.end() , group.begin() , group.end());
            if(itr == nums.end())
            {
                return false;
            }
            itr = itr + group.size();
        }
        return true;
    }
};