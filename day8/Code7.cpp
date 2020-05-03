//
// Created by LuMengLi on 2020/5/3.
//
//
/**求二叉树的结点个数，如果根节点为空，则返回 0。**/
#include <iostream>
struct TreeNode{
    int data;
    struct TreeNode *right;
    struct TreeNode *left;
};
//使用值传递实现
/**
int count;
void totalNode(struct TreeNode* root){
    count++;
    if (root->left!=NULL){
        totalNode(root->left);
    }
    if (root->right!=NULL){
        totalNode(root->right);
    }
}
int countNodes(struct TreeNode* root){
    //记录结点的个数
    count=0;
    //根结点为空
    if (root== NULL){
        return 0;
    }
    totalNode(root);
    return count;
} **/
//使用指针传递实现
void totalNode(struct TreeNode* root,int *count){
    (*count)++;
    if (root->left!=NULL){
        totalNode(root->left,count);
    }
    if (root->right!=NULL){
        totalNode(root->right,count);
    }
}
int countNodes(struct TreeNode* root){
    //记录结点的个数
    int count=0;
    //根结点为空
    if (root== NULL){
        return 0;
    }
    totalNode(root,&count);
    return count;
}






