/*
 Problem Link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/ */

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
    int minOperations(string s) 
    {
        int ans = 0;
        for(int i = 1 ; i < s.length() ; i++)
        {
            if(s[i] != s[i - 1]) continue;
            else
            {
                if(s[i] == '1') s[i] = '0';
                else s[i] = '1';
                ans++;
            }
        }
        return min(ans , (int)s.length() - ans);
    }
};