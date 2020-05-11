//
// Created by LuMengLi on 2020/5/11.
//
/**
 * 二叉树采用二叉链表进行存储（如下所示），每个结点包含数据域Data，左孩子指针域left和右孩子指针域right。
p所指的结点为任一给定结点，编写算法，求从根节点到p所指结点之间的路径，叙述算法思想并给出算法实现，分析时间复杂度。
 */
#include <crtdbg.h>
#include <iostream>
struct BitNode{
    int data;
    struct BitNode *left, *right;
};
typedef struct BitNode *BitTree;
BitTree tree(int *array,int length){
    BitTree root= nullptr;
    if (length%2==0){
        for (int i = 0; i <length/2 ; i++) {
            root->left=(BitTree)malloc(sizeof(BitNode));
            root->right=(BitTree)malloc(sizeof(BitNode));
            root->left->data=array[i];
            root->right->data=array[i+1];
        }
    }else{
        for (int i = 0; i <length ; i++) {
            root->left=(BitTree)malloc(sizeof(BitNode));
            root->right=(BitTree)malloc(sizeof(BitNode));
            root->left->data=array[i];
            root->right->data=array[i+1];
        }
    }
}
void getPath(BitTree root,BitTree p){
    if (root!=NULL){
        getPath(root->left,p);
        getPath(root->right,p);
    }
    if (root->data==p->data){
        printf("%d%s",root->data,"<——");
    }
}
//int main(){
//
//    return 0;
//}
