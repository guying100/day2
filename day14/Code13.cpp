//
// Created by LuMengLi on 2020/5/9.
//
#include <crtdbg.h>

/**2017���Ƽ�Ժ
�����ͷ���ĵ�����A��BΪ�������������������Ͷ������£�
Typeddf struct LNode
{ Element Type data;
    Struct LNode *next;
}LNode, *LinkList;
��д�㷨voidDelete��LinkList *A,LinkList *B��
������� A ��ɾ�����к������ B ��Ԫ����ͬ�Ľ�㡣**/
#include <iostream>
struct LNode{
    int  data;
    struct LNode *next;
};
typedef struct LNode *LinkList;
//�������
void print(LinkList C){
    while (C->data!=NULL){
        printf("%d\n",C->data);
        C=C->next;
    }
}
void Delete(LinkList A,LinkList B){
    if (B->data==NULL){
        printf("%s","�����BΪ�ձ�û��Ҫɾ����Ԫ��");
        return;
    }
    while (B!= nullptr){
        if(A->next->data==B->data){
            //ɾ��A��Ԫ��
            A->next=A->next->next;
            //B��ָ�����
            B=B->next;
        }
        printf("%d\n",A->data);
    }
    printf("%s\n","ɾ����");
    print(A);
}
int main(){
    //��������
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
