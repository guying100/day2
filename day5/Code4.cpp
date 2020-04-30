//
// Created by LuMengLi on 2020/4/30.
//

//两个有序的无头结点的链表La，Lb。编写函数：如何以最优的方式找出二者的交集，并且把结果存在一个新链表中返回。
//
//单链表的类型定义如下：
//
//Typeddf struct LNode{
//
//    Element Type data;
//
//    Struct LNode *next;
//
//}LNode, *ListNode;
//
//函数原型： ListNode* intersection(ListNode *A, ListNode *B)


#include<stdio.h>
#include <malloc.h>
//结构体
typedef struct LNode{
    int data;
    LNode *next;
};
typedef struct LNode LNode;
typedef  struct  LNode * ListNode;
//交集
ListNode intersection(ListNode A, ListNode B){
        //判断不为空
        if (A==NULL ||B==NULL){
            return NULL;
        }
         //1.头节点
        LNode dummy;
        //2.取交集
        ListNode p=&dummy;
        //相等了一起走，值给tail，不相等小的走
        while (A && B){
            if (A->data==B->data){
                p->next=(ListNode)malloc(sizeof(ListNode));
                p=p->next;
                p->data=A->data;
                A=A->next;
                B=B->next;
            } else if(A->data<B->data){
                A=A->next;
            }else{
                B=B->next;
            }
        }
        p->next=NULL;
        return dummy.next;
}
//差集
ListNode difSet(ListNode A, ListNode B){
    //判断不为空
    if (A==NULL ||B==NULL){
        return NULL;
    }
    //1.头节点
    LNode dummy;
    //2.取交集
    ListNode p=&dummy;
    //相等了一起走，值给tail，不相等小的走
    while (A && B){
        if (A->data==B->data){//相等就一起走
            A=A->next;
            B=B->next;
        } else if(A->data<B->data){//小的数值存入新表
            p->next=(ListNode)malloc(sizeof(ListNode));
            p=p->next;
            p->data=A->data;
            A=A->next;
        }else{
            p->next=(ListNode)malloc(sizeof(ListNode));
            p=p->next;
            p->data=B->data;
            B=B->next;
        }
    }
    p->next=NULL;
    return dummy.next;
}
//并集
ListNode merge(ListNode A, ListNode B){
    //判断不为空
    if (A==NULL ||B==NULL){
        return NULL;
    }
    //1.头节点
    LNode dummy;
    //2.取交集
    ListNode p=&dummy;
    //相等了一起走，值给tail，不相等小的走
    while (A && B){
        if (A->data==B->data){//相等就一起走
            p->next=(ListNode)malloc(sizeof(ListNode));
            p=p->next;
            p->data=A->data;
            A=A->next;
            B=B->next;
        } else if(A->data<B->data){//小的数值存入新表
            p->next=(ListNode)malloc(sizeof(ListNode));
            p=p->next;
            p->data=A->data;
            A=A->next;
        }else{
            p->next=(ListNode)malloc(sizeof(ListNode));
            p=p->next;
            p->data=B->data;
            B=B->next;
        }
    }
    p->next=NULL;
    return dummy.next;
}
