//
// Created by LuMengLi on 2020/5/9.
//
#include <crtdbg.h>

/**2017华科计院
假设带头结点的单链表A，B为有序递增表，单链表的类型定义如下：
Typeddf struct LNode
{ Element Type data;
    Struct LNode *next;
}LNode, *LinkList;
编写算法voidDelete（LinkList *A,LinkList *B）
从有序表 A 中删除所有和有序表 B 中元素相同的结点。**/
#include <iostream>
struct LNode{
    int  data;
    struct LNode *next;
};
typedef struct LNode *LinkList;
//输出测试
void print(LinkList C){
    while (C->data!=NULL){
        printf("%d\n",C->data);
        C=C->next;
    }
}
void Delete(LinkList A,LinkList B){
    if (B->data==NULL){
        printf("%s","有序表B为空表，没有要删除的元素");
        return;
    }
    while (B!= nullptr){
        if(A->next->data==B->data){
            //删除A中元素
            A->next=A->next->next;
            //B中指针后移
            B=B->next;
        }
        printf("%d\n",A->data);
    }
    printf("%s\n","删除后");
    print(A);
}
int main(){
    //测试数据
    LNode l1,l2,l3,l4,l5;
    l1.data=4;l1.next=&l2;
    l2.data=5;l2.next=&l3;
    l3.data=6;l3.next=NULL;
    l4.data=5;l4.next=&l5;
    l5.data=6;l5.next=NULL;
    LinkList A=&l1,B=&l4;
    Delete(A,B);
    return 0;
}
