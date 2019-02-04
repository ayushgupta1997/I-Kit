Note : postorder traversal of the tree follows LRN, whereas inorder follows LNR pattern therefore.... lastindex of postorder will give the
root node of the tree and the position of the element in the inorder traversal divides the array into two left and the right subtree 
correspondingly.

unordered_map<int, int> mp;

Node* solve(int post[], int idx, int in[], int start, int end) {
    if(start > end) {
        return NULL;
    }
    Node*  node = newNode(post[idx]);
    int mid = mp[post[idx]];                  // get index in the inorder traversal 
    node->right = solve(post, idx-1, in, mid+1, end);  // recurse into two halves
    node->left = solve(post,idx-(end-mid)-1, in, start, mid-1 );
    return node;
}

Node *buildTree(int in[], int post[], int n)
{
    for (int i = 0; i < n; i++) {
        mp[in[i]] = i;
    }
    return solve(post, n-1, in, 0, n-1 );
}
