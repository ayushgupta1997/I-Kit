

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
void printLeftBoundary(Node* node) {
    if(node==NULL) return;
    if(node->left) {
        cout << node->data << " ";
        printLeftBoundary(node->left);
    }
    else if(node->right){
        cout << node->data << " ";
        printLeftBoundary(node->right);
    }
}
void printRightBoundary(Node* node) {
    if(node==NULL) return;
    if(node->right) {
        
        printRightBoundary(node->right);
        cout << node->data << " ";
    }
    else if(node->left){
       
        printRightBoundary(node->left);
         cout << node->data << " ";
    }
}
void printLeaves(Node* node) {
    if(node==NULL) return;
    printLeaves(node->left);
    if(node->left == NULL && node->right==NULL) {
        cout << node->data<<" ";
    }
    printLeaves(node->right);
    
}

void printBoundary(Node *root)
{
     if(root == NULL) return;
     cout << root->data << " ";
     printLeftBoundary(root->left);
     printLeaves(root->left);
     printLeaves(root->right);
     printRightBoundary(root->right);
}
