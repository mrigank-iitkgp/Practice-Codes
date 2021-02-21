/* Author: Mrigank
Science is what we understand well enough to explain to a computer, 
    Art is everything else we do - Donald E. Knuth */

/*
Problem Link : https://leetcode.com/problems/longest-nice-substring/   */

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
    string longestNiceSubstring(string s) 
    {
        int n = s.length();
        string ans = "";
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                int len = j - i + 1;
                string str = s.substr(i , len);
                unordered_set < char > st;
                for(auto x : str)
                {
                    st.insert(x);
                }
                bool ck = true;
                for(char c = 'a' ; c <= 'z' ; c++)
                {
                    if(st.find(c) != st.end() && st.find(toupper(c)) == st.end())
                    {
                        ck = false;
                        break;
                    }
                    else if(st.find(toupper(c)) != st.end() && st.find(c) == st.end())
                    {
                        ck = false;
                        break;
                    }
                }
                if(ck && ans.length() < str.length())
                {
                    ans = str;
                }
            }
        }
        return ans;
    }
};