/*

  author      : (Ayush Gupta @ayushgupta1997)
  Modified On : [2018-12-15 12:57]	
  topological sorting
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

vector<int> g[105];
stack<int> stk;
bool vis[101];

void dfs(int src) {
	vis[src] = true;
	vector<int>:: iterator it;
	for (it = g[src].begin(); it!=g[src].end(); it++) {
		if(!vis[*it]) {
			dfs(*it);
		}
	}
	stk.push(src);
}

string solve(string arr[], int n, int k) {


	for (int i = 0; i < n-1; i++) {
		
			int x = 0, y=0;
			int l1 = arr[i].length();
			int l2 = arr[i+1].length();

			while(x < l1 && y <l2 && arr[i][x] == arr[i+1][y]) {
				x++;
				y++;
			}
			g[arr[i][x]-'a'].pb(arr[i+1][y]-'a');
		
	}
	
	// lets print the topological order of the graph
	for (int i = 0; i < k; i++) {
		vis[i]=false;
	}
	for (int i = 0; i < k; i++) {
		if(!vis[i]) {
			dfs(i);
		}
	}
	string ans;
	while(!stk.empty()) {
		int top = stk.top();

		ans += (char)(top+'a');
		stk.pop();
	}
	return ans;

}

int main()  {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    //n = no of words, k = total characters to be ordered
    cin >> n >> k;
    string arr[n];
    rep(i,0,n) cin >> arr[i];
    string ans = solve(arr,n, k);
    cout << ans;
    
	return 0;

}
