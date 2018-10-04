//level order traversal
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	int hd; // stores horizontal distance
	Node *left, *right;
	
	Node(int key) 
    { 
        data = key; 
        hd = INT_MAX; 
        left = right = NULL; 
    } 
};
void findBottomView(Node *root) {
	if(root == NULL) return;
	queue<Node*> q;  //level order traversal
	q.push(root);
	map<int,int> mp; // keeps track of node visited later in level order traversal
	int hd =  0;
	root->hd = hd;
	
	while(!q.empty()) {
		Node *temp = q.front();
		q.pop();
		hd = temp->hd;
		mp[hd]=temp->data;
		if (temp->left != NULL) { 
            temp->left->hd = hd-1; 
            q.push(temp->left); 
        } 
		if(temp->right) {
			(temp->right)->hd = hd+1;
			q.push(temp->right);
		}
	}
	for (auto x: mp) {
		cout << x.second << " ";
	}

}
int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->right = new Node(8);
	root->left->right->left = new Node(9);
	root->right->left->right = new Node(10);
	root->right->right->right = new Node(11);
 	findBottomView(root);
	return 0;
}
