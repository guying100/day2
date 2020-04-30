//
// Created by LuMengLi on 2020/4/30.
//
#include <stdlib.h>
typedef  struct ListNode{
    int data;
    ListNode *next;
};
typedef struct ListNode * Listlink;
void reorderList(Listlink head) {
    while(head!=NULL&&head->next!=NULL){
        Listlink p=head;
        //找到尾节点
        Listlink tail;
        while(p->next->next!=NULL){
            p=p->next;
        }
        if (head!=p){//判断是否是最后两个结点
            tail=p->next;
            p->next=NULL;
            //将尾节点插入到当前结点
            tail->next=head->next;
            head->next=tail;
        }
        head=head->next->next;//head移动指针
    }

}
//示例 1:

//给定链表 1->2->3->4, 重新排列为 1->4->2->3.
//示例 2:
//
//给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
//
