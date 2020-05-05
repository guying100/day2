#include <crtdbg.h>

//
// Created by LuMengLi on 2020/5/5.
//
//二叉树采用二叉链表进行存储（如下所示），每个结点包含数据域Data，左孩子指针域left和右孩子指针域right。
// 请设计非递归算法统计二叉树的高度。
//
#include <stdio.h>
#include <malloc.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode *BiTree;

int maxDepth(BiTree root){
    //非递归写法
    //循环队列
    int length=100;
    BiTree queue[length];
    int top=0,tail=0;

    int ret=-1;
    queue[top++]=root;
    while(top!=tail){
        //1.全部出队列
        int lastTop=top;
        while(tail!=lastTop){
            BiTree temp=queue[tail];
            tail=(tail+1)%length;
            if(temp!=NULL){
                queue[top]=temp->left;
                top=(top+1)%length;
                queue[top]=temp->right;
                top=(top+1)%length;
            }
        }
        ret++;
    }
    return ret;
}



