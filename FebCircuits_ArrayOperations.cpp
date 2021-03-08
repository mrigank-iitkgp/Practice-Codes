/* Author: Mrigank
Science is what we understand well enough to explain to a computer, 
    Art is everything else we do - Donald E. Knuth */

/*
 Problem Link : https://www.hackerearth.com/challenges/competitive/february-circuits-21-2/algorithm/array-operations-3-96b9f0e0/ */

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
 
const ll mxsize = 1e5 + 10;
const ll linf = 1e9;
const ld inf = 10000000000.0;
const ll mod = 1e9 + 7;
 
/******************************************** CODE STARTS FROM HERE *************************************************/ 
vl tree;

void build(vl& arr , ll v , ll tl , ll tr)
{
    if(tl == tr)
    {
        tree[v] = arr[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(arr , 2 * v , tl , tm);
        build(arr , 2 * v + 1 , tm + 1 , tr);
        tree[v] = min(tree[2 * v] , tree[2 * v + 1]);
    }
}

ll query(ll v , ll tl , ll tr , ll l , ll r)
{
    if(l > r) return INT64_MAX;
    if(l == tl && r == tr) return tree[v];
    ll tm = (tl + tr / 2);
    return min(query(2 * v , tl , tm , l , min(r , tm)) , 
                query(2 * v + 1 , tm + 1 , tr , max(l , tm + 1) , r));
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

    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vl arr(n);
        ll i , j;
        fo(i , n) cin >> arr[i];
        tree.clear();
        tree.resize(4 * n);
        build(arr , 1ll , 0ll , n - 1);
        ll ans = INT64_MIN;
        fo(i , n)
        {
            ll val = arr[i];
            if(val < 0) val = 0;
            ans = max(ans , val);
            val = arr[i];
            Fo(j , i + 1 , n)
            {
                val += arr[j];
                ll min_val = query(1ll , 0 , n - 1 , i , j);
                if(min_val < 0) val += abs(min_val);
                ans = max(ans , val);
                val -= min_val;
            }
        }
        cout << ans << endl;
    }    
 } 