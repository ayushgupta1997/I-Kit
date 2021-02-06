#include <bits/stdc++.h>

using namespace std;

int mat[100][100];
int n = 8;

bool safeState(int row, int col) {
	//check left
	for (int i = 0; i < n; i++) {
		if(mat[row][i] == 1)
			return false;
	}
	int i,j;
	for (i = row, j= col; i>=0 && j>=0; i--,j--){ // upper diagonal
		if(mat[i][j])
			return false;
	}
	for (i = row, j= col; i<n && j>=0; i++,j--){ // lower diagonal
		if(mat[i][j])
			return false;
	}
	return true;

}
bool solveNQueen(int col) {
	if(col >= n)
		return true; // the problem is solved here
	for (int i = 0; i < n; i++) {
		if(safeState(i, col)) {
			mat[i][col] = 1;  // place the queen
			if(solveNQueen(col+1)) return true;
			mat[i][col] = 0;
		}

	}
	return false;
}

int main() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	if(solveNQueen(0)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mat[i][j] << " ";
			}
			cout << "\n";
	    }
	}
	else {
		cout << "NO";
	}
	return 0;
}
