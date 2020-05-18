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
    struct ListNode* q=head;
    int nums[10000];
    int count=0,m=0;
    //将链表中的值赋给一个数组中存储
    while (head!= NULL){
        nums[count]=head->val;
        count++;
        head=head->next;

    }
    //确定可以分为几个小的链表组
    m=count%k==0?count/k:count/k+1;
    //循环
    for (int i = 0; i <m ; i++) {
        int index=0;
        //判断是否是最后一个链表组，如果说是最后一个的话改变index的值即第二次循环的次数
        if(count%k!=0 && (i+1)==(count/k+1)){
            index=count-(i+1)*k;
        } else{
            index=k;
        }
        //第二次循环，在每个链表组中，设置其值
        for (int j = 0; j <index; j++) {
            //找规律发现有这样的翻转的规律
            p->val=nums[(i+1)*k-j-1];
            p=p->next;
        }
    }
    return q;
}