// program to  print all paths from moving down and right source = top left, destination  = bottom right
#include <bits/stdc++.h>

using namespace std;

int n,m;
int mat[100][100];

void solve(int x, int y, vector<int> v) {
	if(x == n-1) {
		for (int i = y; i < m; i++) {
			v.push_back(mat[x][i]);
		}
		for (auto x: v) {
			cout << x << " ";
		}
		cout << endl;
		v.clear();
		return;
	}
	if(y == m-1) {
		for (int i = x; i < n; i++) {
			v.push_back(mat[i][y]);
		}
		for (auto x: v) {
			cout << x << " ";
		}
		cout << endl;
		v.clear();
		return;
	}
	v.push_back(mat[x][y]);
	solve(x+1, y, v);
	solve(x, y+1, v);

}
int main() {
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	solve(0, 0, v);
}
