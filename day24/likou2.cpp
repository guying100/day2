//
// Created by LuMengLi on 2020/5/19.
//
#include <cmath>

/**
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
 */
//注意！！！！有问题：超出数据的长度的不行
struct ListNode {
    int val;
    struct ListNode *next;
};
//将链表中的值转为数字的函数
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <iostream>
//链表中结点的构造方法
struct ListNode* Createnode(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
int getNumber(struct ListNode* l){
    int i=0,number=0;
    while(l!= NULL){
        number=number+l->val*pow(10,i);
        i++;
        l=l->next;
    }
    return number;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head=l1;
    int oneA=getNumber(l1),oneB=getNumber(l2),sum=0,k=0;
    sum=oneA+oneB;
    while (sum/(int)pow(10,k)!=0){
        struct ListNode* node = Createnode((sum/(int)pow(10,k))%10);
        l1->next=node;
        printf("%d\n",node->val);
        l1=l1->next;
        k++;
    }
    return head;
}