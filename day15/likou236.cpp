//
// Created by LuMengLi on 2020/5/10.
//
/**
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
 最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
 使用深度遍历的方法
 */
 /**
  *  TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        }
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
  */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    };
TreeNode* ans;
bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return false;
    bool lson = dfs(root->left, p, q);
    bool rson = dfs(root->right, p, q);
    if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
        ans = root;
    }
    return lson || rson || (root->val == p->val || root->val == q->val);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, p, q);
    return ans;
}