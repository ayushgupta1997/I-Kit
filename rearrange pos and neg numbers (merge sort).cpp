/*

  author      : (Ayush Gupta @ayushgupta1997)
  Modified On : 
  
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

int arr[1005];
void reverse(int start, int end) {
    if(start < end) {
        swap(arr[start], arr[end]);
        reverse(++start, --end);
    }
}
 
void merge(int arr[], int l, int mid, int r) {
	int i=l; int j = mid+1;
	while(i<=mid && arr[i]<0) {
		i++;
	}
	while(j<=r && arr[j] < 0) {
		j++;
	}
	reverse(i,mid);
	reverse(mid+1,j-1);
	reverse(i,j-1);
}

void mergePosNeg(int arr[], int l, int r) {
	if(l < r) {
		int mid = (l+(r-l)/2);
		mergePosNeg(arr, l, mid);
		mergePosNeg(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

int main()  {
   
    int n;
    cin  >> n;
    //int arr[n];
    rep(i,0,n) {
    	cin  >> arr[i];
    }
    mergePosNeg(arr,0, n-1);
    rep(i,0,n) {
    	cout << arr[i] << " ";
    }
    
	return 0;

}
