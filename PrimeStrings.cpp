/* Author: Mrigank
Science is what we understand well enough to explain to a computer, 
    Art is everything else we do - Donald E. Knuth */

/*
Problem Link : https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/primestring/  */

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

vector < int > prime;
vector < int > sum;
vector < int > check;
void sieve()
{
    prime.resize(mxsize , 1);
    sum.resize(mxsize , 0);
    check.resize(mxsize , 0);
    prime[0] = 0;
    prime[1] = 0;
    for(ll i = 2 ; i * i < mxsize ; i++)
    {
        if(prime[i] == 1)
        {
            for(ll k = i * i ; k < mxsize ; k = k + i)
            {
                prime[k] = 0;
            }
        }
    }
}

int main()
{
    /**************************************************************/
    fastIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    #endif
    /**************************************************************/    
    sieve();
    ll t;
    cin >> t;
    //t = 1;
    while(t--)
    {
        string s;
        cin >> s;
        unordered_map < char , int > mp;
        for(auto x : s)
        {
            mp[x]++;
        }
        bool ok = true;
        if(!prime[mp.size()]) ok = false;
        if(!ok) 
        {
            cout << "NO" << endl;
            continue;
        }
        for(auto x : mp)
        {
            if(!prime[x.second]) ok = false;
            if(!ok) break;
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
 } 