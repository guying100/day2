//
// Created by LuMengLi on 2020/5/20.
//

/**
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
 */
#include <malloc.h>
#include <iostream>

//注意！！！！有问题：超出数据的长度的不行
struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode LN;

LN* Createnode(int val)
{
    LN *node = (LN *)malloc(sizeof(LN));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    LN *head = l1;
    while(l1 && l2 && l1->next && l2->next)
    {
        //printf("1");
        l1->val += l2->val;
        l1 = l1->next;
        l2 = l2->next;
    }
    if(l1 && l2)
    {
        l1->val += l2->val;
        l2 = l2->next;
    }

    if(l1 && !(l1->next) && l2)
    {
        while(l2)
        {
            LN* node = Createnode(l2->val);
            l1->next = node;
            printf("l1 is %d\t next is %d\n",l1->val,l1->next->val);
            l1 = l1->next;
            l2 = l2->next;
        }

    }
    //printf("1");

    l1 = head;
    while(l1)
    {
        if(l1->val >= 10)
        {
            l1->val = l1->val % 10;
            if(l1->next)
            {
                l1->next->val += 1;
            }
            else
            {
                LN *node = (LN *)malloc(sizeof(LN));
                node->next = NULL;
                node->val = 1;
                l1->next = node;
            }
        }
        l1 = l1->next;
    }

    return head;

}