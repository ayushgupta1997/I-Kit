
int toSum(Node *node) {
    if(node==NULL) return 0;
    int val = node->data;
    node->data = toSum(node->left)+toSum(node->right);
    return val+node->data;
    
}
void toSumTree(Node *node)
{
    toSum(node);
    return;
}
