/*
 Problem Link: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/ */

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
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        ll lo = 1 , hi = 1000000000;
        ll cnt;
        while(lo < hi)
        {
            ll mid = (hi + lo) / 2;
            cnt = 0;
            for(auto num : nums)
            {
                cnt += (num / mid) - (num % mid == 0);
            }
            if(cnt > maxOperations)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        return lo;
    }
};