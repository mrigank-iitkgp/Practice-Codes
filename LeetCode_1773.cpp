/* Author: Mrigank
Science is what we understand well enough to explain to a computer, 
    Art is everything else we do - Donald E. Knuth */

/*
 Problem Link : https://leetcode.com/problems/count-items-matching-a-rule/    */

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
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) 
    {
        int ans = 0;
        for(auto item : items)
        {
            if((ruleKey == "type" && item[0] == ruleValue) || (ruleKey == "color" && ruleValue == item[1]) || (ruleKey == "name" && ruleValue == item[2]))  ans++;
        }
        return ans;
    }
};