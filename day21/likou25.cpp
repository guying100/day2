//
// Created by LuMengLi on 2020/5/16.
//
/**给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。**/
#include<iostream>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode* p=head;
    int nums[10000];
    int count=0;
    //1.将链表转化为数组
    while(p!=NULL){
        nums[count++]=p->val;
        p=p->next;
    }
    //2.进行反转
    int m,n,temp;
    for(int i=0;i<count/k;i++){
        m=i*k;
        n=(i+1)*k-1;
        while(m<n){
            temp=nums[m];
            nums[m]=nums[n];
            nums[n]=temp;
            m++,n--;
        }
    }
    //3.将数组转化为链表
    struct  ListNode dummy;
    p=&dummy;
    for(int i=0;i<count;i++){
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->next->val=nums[i];
        p=p->next;
    }
    p->next=NULL;
    return dummy.next;
}