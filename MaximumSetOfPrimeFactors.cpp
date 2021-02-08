/* Author: Mrigank
Science is what we understand well enough to explain to a computer, 
    Art is everything else we do - Donald E. Knuth */

/*
Problem Link : https://www.spoj.com/problems/MMS/  */

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
 
const ll mxsize = 1e5 + 3;
const ll linf = 1e9;
const ld inf = 10000000000.0;
const ll mod = 1e9 + 7;
 
/******************************************** CODE STARTS FROM HERE *************************************************/ 
vector < ll > primes;
void sieve()
{
    primes.resize(mxsize);
    for(int i = 2 ; i < mxsize ; i++)
    {
        primes[i] = i;
    }
    for(int i = 2 ; i < mxsize ; i = i + 2)
    {
        primes[i] = 2;
    }
    for(int i = 3 ; i * i < mxsize ; i++)
    {
        if(primes[i] == i)
        {
            for(int k = i * i ; k < mxsize ; k = k + i)
            {
                primes[k] = i;
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
    ll n;
    ll cnt = 1;
    while(cin >> n && n != 0)
    {
        vl arr(n);
        ll i;
        fo(i , n) cin >> arr[i];
        ll ans = 0;
        ll val = -1;
        fo(i , n)
        {
            ll sum = 0;
            ll temp = arr[i];
            while(temp != 1)
            {
                sum += primes[temp];
                temp = temp / primes[temp];
            }
            if(sum > ans)
            {
                ans = sum;
                val = arr[i];
            }
        }
        //Case 1: The sum of 26’s prime factors: 15
        cout << "Case " << cnt++ << ": " << "The sum of " << val << "’s prime factors: " << ans << endl;
    }
 } 