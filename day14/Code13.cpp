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
    if (B->next->data==NULL){
        printf("%s","有序表B为空表，没有要删除的元素");
        return;
    }
    bool flag= false;//标记A是否移动
    while (B->next!= NULL){
        if(A->next->data==B->next->data){
            //删除A中元素
            A->next=A->next->next;
            //B中指针后移
            B=B->next;
        }else{
            A=A->next;
            flag=true;
        }
    }
    //如果A没有移动过，还停留头节点中，将A向后移动一位；
    if (!flag){
        A=A->next;
    }
    printf("%s\n","删除后");
    print(A);
}
//int main(){
//    //测试数据
//    LNode l1,l2,l3,l4,l5,headA,headB;
//    headA.next=&l1;headB.next=&l4;
//    l1.data=2;l1.next=&l2;
//    l2.data=6;l2.next=&l3;
//    l3.data=7;l3.next=NULL;
//    l4.data=6;l4.next=&l5;
//    l5.data=7;l5.next=NULL;
//    LinkList A=&headA,B=&headB;
//    Delete(A,B);
//    return 0;
//}
