   //Iterative 0ms Solution
   bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q== NULL) {
            return true;
        }
        if(p==NULL || q== NULL){
            return false;
        }
        queue<TreeNode*> que1,que2;
        que1.push(p);
        que2.push(q);
        while(!que1.empty() && !que2.empty()) {
            TreeNode *a = que1.front();
            TreeNode *b = que2.front();
            if(a->val != b->val) {
                return false;
            }
            que1.pop();
            que2.pop();
            if(a->left && b->left) {
                que1.push(a->left);
                que2.push(b->left);
            }
            else if(a->left || b->left) {
                return false;
            }
            if(a->right && b->right) {
                que1.push(a->right);
                que2.push(b->right);
            }
            else if(a->right || b->right) {
                return false;
            }
        }
        return true;
    }
    
    
    //Recursive 4ms Solution
    
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return 1;
        else if((p == NULL && q!=NULL) || (p != NULL && q==NULL)) return 0;
        return (p->val == q->val)&&(isSameTree(p->left,q->left))&&(isSameTree(p->right,q->right));
        
    }
