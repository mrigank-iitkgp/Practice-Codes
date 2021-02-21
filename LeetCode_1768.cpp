/* Author: Mrigank
Science is what we understand well enough to explain to a computer, 
    Art is everything else we do - Donald E. Knuth */

/*
 Problem Link : https://leetcode.com/problems/merge-strings-alternately/    */

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
    string mergeAlternately(string word1, string word2) 
    {
        string ans;
        int i = 0 , j = 0;
        while(i < word1.length() && j < word2.length())
        {
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }
        while(i < word1.length())
        {
            ans.push_back(word1[i++]);
        }
        while(j < word2.length())
        {
            ans.push_back(word2[j++]);
        }
        return ans;
    }
};