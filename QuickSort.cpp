/* Author: Mrigank
Science is what we understand well enough to explain to a computer, 
    Art is everything else we do - Donald E. Knuth */

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
 
const ll mxsize = 1e6 + 10;
const ll linf = 1e9;
const ld inf = 10000000000.0;
const ll mod = 1e9 + 7;
 
/******************************************** CODE STARTS FROM HERE *************************************************/ 

int partition(vl& arr , ll low , ll high)
{
    ll pivot = arr[high];
    ll partitionIdx = low;
    for(ll j = low ; j < high ; j++)
    {
        if(arr[j] <= pivot)
        {
            swap(arr[partitionIdx] , arr[j]);
            partitionIdx++;
        }
    }
    swap(arr[partitionIdx] , arr[high]);
    return partitionIdx;
}

int partitionRandomized(vl& arr , ll low , ll high)
{
    int randomNumber = low + (high - low) % rand();
    deb2(randomNumber , high);
    swap(arr[randomNumber] , arr[high]);
    return partition(arr , low , high);
}
void quickSort(vl& arr , ll low , ll high)
{
    if(low < high)
    {
        ll pivotIdx = partitionRandomized(arr , low , high);
        quickSort(arr , low , pivotIdx - 1);
        quickSort(arr , pivotIdx + 1 , high);
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

    ll n ;
    cin >> n;
    vl arr(n);
    ll i;
    fo(i , n) cin >> arr[i];
    fo(i , n) cout << arr[i] << " ";
    cout << endl;
    quickSort(arr , 0 , n - 1);
    fo(i , n) cout << arr[i] << " ";
    cout << endl;
 } 