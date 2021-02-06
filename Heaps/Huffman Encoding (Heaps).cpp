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

struct Node {
    char data;
    int freq;
    Node* left,*right;
    Node(char val, int freq) {
        left=right=NULL;
        this->data = val;
        this->freq = freq;
    }
};

class compare
{
public:
    int operator() ( Node* p1, Node* p2)
    {
        return ((p1->freq) > (p2->freq)) ;
    }
};
void printCodes(Node *root,string temp=""){
	if(root==NULL)
		return;
	
	if(root->left==NULL  &&  root->right==NULL){
		cout<<temp<<" ";
		return;
	}
	
	printCodes(root->left,temp+'0');
	printCodes(root->right,temp+'1');
	
}

void solveHuffmanCodes(string data, int freq[], int n) {
    priority_queue<Node*, vector<Node*>, compare> q;
    Node *left, *right,*top;
    for (int i = 0; i < n; i++) {
        q.push(new Node(data[i], freq[i]));
    }
    while(q.size()>1){
        Node* left = q.top();
        q.pop();
        Node* right = q.top();
        q.pop();
        top = new Node('$', left->freq+right->freq);
        top->left = left;
        top->right = right;
        q.push(top);
    }    
    printCodes(q.top());
}

int main() {
    int t;
    cin >> t;
    //cin.ignore();
    while(t--) {
        cin.ignore();  
        string s;
        cin >> s;
        int l = s.size();
        int freq[l];
        rep(i,0,l) {
            cin >> freq[i];
        }
        solveHuffmanCodes(s, freq, l);
        cout << endl;
    }

return 0;
}
