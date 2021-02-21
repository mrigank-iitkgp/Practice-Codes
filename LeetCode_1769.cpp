/* Author: Mrigank
Science is what we understand well enough to explain to a computer, 
    Art is everything else we do - Donald E. Knuth */

/*
 Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/    */

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
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.length();
        vector < int > ans(n);
        for(int i = 0 ; i < n ; i++)
        {
            int val = 0;
            for(int j = 0 ; j < n ; j++)
            {
                if(i != j && boxes[j] == '1')
                {
                    val += abs(j - i);
                }
            }
            ans[i] = val;
        }
        return ans;
    }
};