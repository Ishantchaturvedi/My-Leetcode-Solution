class Solution {
public:
    bool solve(TreeNode* root1 , TreeNode* root2){
        if(root1==NULL && root2==NULL)
        return true;
        if(root1==NULL || root2==NULL)
        return false;
        if(root1->val!=root2->val)
        return false;
        bool b= solve(root1->left,root2->left) && solve(root1->right,root2->right);
        bool c= solve(root1->left,root2->right) && solve(root1->right,root2->left);
        return b || c;  
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return solve(root1 , root2);
        
    }
};