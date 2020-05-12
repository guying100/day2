//
// Created by LuMengLi on 2020/5/12.
//
/**
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
 */
#include <malloc.h>
#include <crtdbg.h>
//链式存储结构
typedef struct linkNode{
    int data;//数据域
    struct linkNode *next;//指针域
}MinStack,*linkList;
/** initialize your data structure here. */
//obj指向链栈顶的元素,head为链表头
MinStack* minStackCreate() {
    linkList head=(linkList)malloc(sizeof(MinStack));
    head->next=NULL;
    return head;
}

void minStackPush(MinStack* obj, int x) {
    linkList node=(linkList)malloc(sizeof(MinStack));
    node->data=x;
    node->next=obj->next;
    obj->next=node;
}

void minStackPop(MinStack* obj) {
    //删除栈顶操作
    obj->next=obj->next->next;
}

int minStackTop(MinStack* obj) {
    //注意obj是表头
    return obj->next->data;
}

int minStackGetMin(MinStack* obj) {
    linkList p=(linkList)malloc(sizeof(MinStack));
    p=obj;
    p=p->next;
    int min=p->data;
    //遍历链表
    while (p->next!= NULL){
        if (p->next->data<min){
            min=p->next->data;
        }

        p=p->next;
    }
    return min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/