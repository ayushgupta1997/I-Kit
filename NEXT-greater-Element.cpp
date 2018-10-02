/*

  author      : (Ayush Gupta @ayushgupta1997)
  Modified On : 

7 
1 9 3 10 4 20 2
output : (in the same order that is why we have used the map )
1 9
9 10
3 10
10 20
4 20
20 -1
2 -1

  
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

void solve(int arr[], int n) {
	stack<int> s;
	s.push(arr[0]);
	map<int,int> mp;
	for (int i = 1; i < n; i++) {
		if(s.empty()) {
			s.push(arr[i]);
		}
		while(!s.empty() && (s.top()<arr[i])) {
			mp[s.top()] = arr[i]; // this will be next greater element on the right side of the array 
			s.pop();
		}
		s.push(arr[i]);
	}
	while(!s.empty()) {
		mp[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " " << mp[arr[i]] << "\n";
	}
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
    solve(arr, n);
	return 0;

}
