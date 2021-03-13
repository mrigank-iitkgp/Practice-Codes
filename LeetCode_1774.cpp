/* Author: Mrigank
Science is what we understand well enough to explain to a computer, 
    Art is everything else we do - Donald E. Knuth */

/*
 Problem Link : https://leetcode.com/problems/closest-dessert-cost/    */

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
    typedef long long int ll;
    ll ans;
    void helper(vector < int >& toppingCosts , int target , int cost , int idx)
    {
        if(abs(target - cost) < abs(target - ans) || (abs(target - cost) == abs(target - ans) && cost < ans))
        {
            ans = cost;
        }
        if(idx >= toppingCosts.size()) return;
        helper(toppingCosts , target , cost , idx + 1);
        helper(toppingCosts , target , cost + toppingCosts[idx] , idx + 1);
        helper(toppingCosts , target , cost + 2 * toppingCosts[idx] , idx + 1);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) 
    {
        ans = baseCosts[0];
        for(auto baseCost : baseCosts)
        {
            helper(toppingCosts , target , baseCost , 0);
        }
        return ans;
    }
};