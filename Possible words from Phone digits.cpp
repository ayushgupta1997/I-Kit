#include <bits/stdc++.h>

using namespace std;


string dict[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void solve(int arr[], int n) {
    int i;
    queue<string> q;
    for (int i=0; i < dict[arr[0]].length(); i++) {
        string temp = "";
        temp += dict[arr[0]][i];
        q.push(temp);
    }
    i=1;
    while(!q.empty()) {
        if(i==n) {
            break;
        }
        int size = q.size();
        
        while(size--) {
            string temp = q.front();
            q.pop();
            for(int j=0; j<dict[arr[i]].length(); j++) {
                q.push(temp+dict[arr[i]][j]);
            }
        }
        i++;
    }
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]-=2;
        }
        solve(arr, n);
        cout << endl;
    }
    return 0;
}
