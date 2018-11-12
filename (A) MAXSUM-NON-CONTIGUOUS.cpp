/*

  author      : (Ayush Gupta @ayushgupta1997)
  Modified On : [2018-11-11 00:34]	
  
 */

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define rep(i, a, b)             for(int i = a; i < b; i++)
#define REP(i, a, b)             for(int i = a; i <= b; i++)
#define sc(n)                    scanf("%d",&n)
#define sc2(a,b)                 scanf("%d%d", &a, &b) 
#define pb                       push_back
#define ff                       first
#define ss                       second
#define mp                       make_pair
#define mt                       make_tuple
#define SET(a, b)                memset(a,b,sizeof(a)) 
#define all(v)                   (v).begin(),(v).end()
#define rall(v)                  (v).rbegin(),(v),rend()
#define MAX 200005
#define MOD 1000000007

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef double ld;

int solve(int arr[], int n) {
	int a=arr[0],b=0,c;
	rep (i,1,n) {
		c=max(a,b);
		a=b+arr[i];
		b=c;
	}
	return max(a,b);
}

int main()  {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int arr[n];
    rep(i,0,n) {
    	cin >> arr[i];
    }
    int maxsum = solve(arr, n);
    cout << maxsum << endl;
	return 0;

}
