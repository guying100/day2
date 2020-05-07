
//
// Created by LuMengLi on 2020/5/7.
//
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool check(TreeNode *o, TreeNode *t) {
    if (!o && !t) return true;//都为空时
    if ((o && !t) || (!o && t) || (o->val != t->val)) return false;
    return check(o->left, t->left) && check(o->right, t->right);//递归实现
}

bool dfs(TreeNode *o, TreeNode *t) {
    if (!o) return false;
    return check(o, t) || dfs(o->left, t) || dfs(o->right, t);
}

bool isSubtree(TreeNode *s, TreeNode *t) {
    return dfs(s, t);
}
