
/* Author: Mrigank
Science is what we understand well enough to explain to a computer, 
    Art is everything else we do - Donald E. Knuth */

/*
 Problem Link : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc#problem  */

#include <iostream>
#include <sstream>
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
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll, int> PLI;
typedef pair < ll , ll > PLL;
typedef pair<int, int> PII;
typedef vector < ll > vl;
typedef vector < int > vi;
typedef vector < bool > vb;
typedef vector < pair < int , int > > vpi;
typedef vector < pair < ll , ll > > vpl;
typedef vector < pair < ll , bool > > vpb;
typedef vector < vector < int > > vvi;
typedef vector < vector < ll > > vvl;
 
 
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define pi pair < ll , ll >
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x , val) memset(x , val , sizeof(x))
#define deb(x) cout<<#x<<" :: "<<x<<"\n"
#define deb2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n"
#define deb3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n"
#define all(x) x.begin() , x.end()
#define alls(x , y) x.begin() , x.end() , y
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
 
const ll mxsize = 1e6 + 10;
const ll linf = 1e9;
const ld inf = 10000000000.0;
const ll mod = 1e9 + 7;
 
/******************************************** CODE STARTS FROM HERE *************************************************/ 

unordered_map < ll , ll > closingBrackets;
string res;

void findClosingBrackets(string& s)
{
    stack < pair < char , int > > st;
    for(ll i = 0 ; i < s.length() ; i++)
    {
        if(s[i] == '(')
        {
            st.push(mp(s[i] , i));
        }
        else if(s[i] == ')')
        {
            pair < char , int > val = st.top();
            st.pop();
            closingBrackets[val.S] = i;
        }
    }
}

void expand(string& s , ll l , ll r)
{
    if(l > r) return;
    for(ll i = l ; i <= r ; i++)
    {
        if(s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
        {
            res.pb(s[i]);
        }
        else if(s[i] >= '1' && s[i] <= '9')
        {
            ll val = s[i] - '1';
            for(ll j = 0 ; j < val ; j++)
            {
                expand(s , i + 2 , closingBrackets[i + 1] - 1);
            }
        }
    }
}

pair < ll , ll > solve()
{
    pair < ll , ll > ans;
    ans.F = 0;
    ans.S = 0;
    for(auto x : res)
    {
        if(x == 'N')
        {
            ans.S = (ans.S - 1 + 1000000000) % 1000000000;
        }
        else if(x == 'S')
        {
            ans.S = (ans.S + 1 + 1000000000) % 1000000000;
        }
        else if(x == 'E')
        {
            ans.F = (ans.F + 1 + 1000000000) % 1000000000;
        }
        else
        {
            ans.F = (ans.F - 1 + 1000000000) % 1000000000;
        }
    }
    return ans;
}

int main()
{
    /**************************************************************/
    fastIO;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt" , "r" , stdin);
    //     freopen("output.txt" , "w" , stdout);
    // #endif
    /**************************************************************/    

    ll t;
    cin >> t;
    ll tc = 1;
    while(t--)
    {
        string s;
        cin >> s;
        closingBrackets.clear();
        res.clear();
        findClosingBrackets(s);
        ll n = s.length();
        expand(s , 0ll , n - 1);
        //cout << res << endl;
        pair < ll , ll > ans = solve();
        cout << "Case #" << tc++ << ": " << ans.F % 1000000000 + 1 << " " << ans.S % 1000000000 + 1 << endl;
    }
 } 