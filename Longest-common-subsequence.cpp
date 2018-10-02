int Solution::longestConsecutive(const vector<int> &A) {
    int n = A.size();
    unordered_set<int> s;
    int ans = 0;
    for (int i = 0; i <n; i++) {
        s.insert(A[i]);
    }
    for (int i= 0; i < n; i++) {
        if(s.find(A[i]-1) == s.end()) {
            int j = A[i];
            while(s.find(j)!=s.end()) {
                j++;
            }
            ans = max(ans, j-A[i]);
        }
    }
    return ans;
}
