//
// Created by LuMengLi on 2020/5/3.
//
//求二叉树所有具有两个子女的结点个数，如果根节点为空，则返回 0。
#include <iostream>
struct TreeNode{
    int data;
    struct TreeNode *right;
    struct TreeNode *left;
};
//使用指针传递实现
void totalNode(struct TreeNode* root,int *count){
    if (root->left!=NULL && root->right!=NULL){
        (*count)++;
        totalNode(root->left,count);
        totalNode(root->right,count);
    }
    if (root->left!=NULL && root->right==NULL){
        totalNode(root->left,count);
    }
    if (root->right!=NULL && root->left==NULL){
        totalNode(root->right,count);
    }
}
int countChildNodes(struct TreeNode* root){
    //记录结点的个数
    int count=0;
    //根结点为空
    if (root== NULL){
        return 0;
    }
    totalNode(root,&count);
    return count;
}
