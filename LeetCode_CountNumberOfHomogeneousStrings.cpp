*
 Problem Link: https://leetcode.com/problems/count-number-of-homogenous-substrings/

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
    int mod = 1e9 + 7;
    typedef long long int ll;
    int countHomogenous(string s) 
    {
        ll n = s.length();
        if(n == 1) return 1;
        char prev = s[0];
        ll len = 1;
        ll ans = 0;
        for(int i = 1 ; i < n ; i++)
        {
            if(prev == s[i])
            {
                len++;
            }
            else
            {
                if(len % 2 == 0)
                {
                    ll val = len / 2;
                    ans = (ans % mod + ((val % mod) * (len + 1) % mod) % mod) % mod;
                }
                else
                {
                    ll val = (len + 1) / 2;
                    ans = (ans % mod + ((len % mod) * (val % mod) % mod) % mod);
                }
                len = 1;
                prev = s[i];
            }
        }
        if(len % 2 == 0)
        {
            ll val = len / 2;
            ans = (ans % mod + ((val % mod) * (len + 1) % mod) % mod) % mod;
        }
        else
        {
            ll val = (len + 1) / 2;
            ans = (ans % mod + ((len % mod) * (val % mod) % mod) % mod);
        }
        return ans;
    }
};