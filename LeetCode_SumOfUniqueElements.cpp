/*
 Problem Link: https://leetcode.com/problems/sum-of-unique-elements*/

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
    int sumOfUnique(vector<int>& nums) 
    {
        unordered_map < int , int > mp;
        for(auto num : nums)
        {
            mp[num]++;
        }
        int ans = 0;
        for(auto x : mp)
        {
            if(x.second == 1) ans += x.first;
        }
        return ans;
    }
};