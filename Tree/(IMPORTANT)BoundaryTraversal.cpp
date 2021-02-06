/*

  author      : (Ayush Gupta @ayushgupta1997)
  Modified On : [2018-11-10 22:35]	
  
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

struct Node {
	int data;
	struct Node *left, *right;
};

void printBoundaryLeft(Node* node) {
	if(node == NULL) return;
	if(node->left) {
		cout << node->data << " ";
		printBoundaryLeft(node->left);
	}
	else if(node->right){
		cout << node->data << " ";
		printBoundaryLeft(node->right);
	}
}
void printBoundaryRight(Node* node) {
	if(node == NULL) return;
	if(node->right) {
		printBoundaryLeft(node->right);
		cout << node->data << " ";
	}
	else if(node->left){
		printBoundaryLeft(node->left);
		cout << node->data << " ";
	}
}
void printLeaves(Node* node) {
	if(node == NULL) return;
	
	if(!(node->left) && !(node->right)) {
		cout << node->data<< " ";
	} 
	printLeaves(node->left);
	printLeaves(node->right);	
}

void printBoundary(Node* root) {
	if(root == NULL) {
		return;
	}
	cout << root->data << " ";
	printBoundaryLeft(root->left);
	printLeaves(root);
	printBoundaryRight(root->right);
}
Node* newNode(int a) {
	Node* temp = (Node *)malloc(sizeof(struct Node));
	temp->data = a;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main()  {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    struct Node *root         = newNode(20); 
    root->left                = newNode(8); 
    root->left->left          = newNode(4); 
    root->left->right         = newNode(12); 
    root->left->right->left   = newNode(10); 
    root->left->right->right  = newNode(14); 
    root->right               = newNode(22); 
    root->right->right        = newNode(25); 
    printBoundary(root);
	return 0;

}
