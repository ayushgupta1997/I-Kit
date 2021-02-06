// Given a String return all the possible balanced strings with minimum removal of character.
//Classic BFS problem
class Solution {
public:
    bool checkBalanced(string s) {
        int cnt = 0;
        for (char x: s) {
            if(x == '(') cnt++;
            else if(x == ')') cnt--;
            if(cnt < 0) return 0;
        }
        return (cnt==0);
    }
    vector<string> removeInvalidParentheses(string s) {
        map<string, bool> vis;
        vector<string> ans;
        string empt="";
        queue<string> q;
        q.push(s);
        int found = 0;
        while(!q.empty()) {
            string temp = q.front();
            q.pop();
            if(vis[temp]) continue;
            vis[temp]=1;
            if(checkBalanced(temp)) {
                ans.push_back(temp);
                found = 1;
            }
            if(found == 1) continue;
            for (int i = 0; i < temp.size(); i++) {
                if(temp[i] == '(' || temp[i] == ')') {
                    string z = temp.substr(0,i)+temp.substr(i+1);
                    q.push(z);
                }
            }
            
        }
        
        return ans;
        
    }
};
