//
// Created by LuMengLi on 2020/5/6.
//

//给定一颗n个结点的二叉排序树（即BST），每个结点均存放一个整数，其结点格式为[lchild][data][rchild].
//
//令half=（BST中的最大值+BST中的最小值）/2。
//
//设计一个算法BinTree findNearMid（BinTree *root）.
//
//完成（1）找出BST中最大和最小值以计算half的值；
//
//（2） 返回大于half且与half相差最小的结点。



#include <crtdbg.h>
#include <math.h>
struct BinNode{
    int data;
    struct BinNode *lchild;
    struct BinNode *rchild;
};
typedef struct BinNode *BinTree;
BinTree findNearMid(BinTree root){
    int max=0,min=0,half=0,near=0;
    BinTree p=root,k=root,node;
    //找出BST中最小值
    while(root->lchild!=NULL){
        root=root->lchild;
    }
    min=root->data;
    //找到BST中最大值
    while(p->rchild!=NULL){
        p=p->rchild;
    }
    max=p->data;
    half=(min+max)/2;//计算half
    while(k!=NULL){
        near=abs(half-k->data);
        if (half<k->data){
            if (near<abs(k->lchild->data-half)){
                node=p;
            }else{
                k=k->lchild;
            }
        }
    }
    return node;
}