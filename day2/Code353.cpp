//
// Created by LuMengLi on 2020/4/27.
//��������ѧ�ϻ����
//���ֲ���{-36 -25 0 12 14 29 35 47 76 100}��������ʮ�������ж��ֲ��ҡ�
//����������
//��������Ҫ���ҵ����ݣ�
//14
//-25
//121
//���������
//14�ǵ�5���������Ҵ���Ϊ1��
//-25�ǵ�2���������Ҵ���Ϊ2��
//����ʧ�ܡ�
#include <iostream>
using namespace std;
void findValue(int value){
    int find[]={-36,-25,0,12,14,29,35,47,76,100},length;
    int position=-1,times=1;//position���ڼ�¼valueλ�ڵڼ�����,times��¼���ҵĴ���
    length= sizeof(find)/ sizeof(int);//ע��������ĳ��ȵķ���
    for (int i = 0; i < length ; i++) {
        if (value==find[i]){//�ҵ���value��λ��
            position=i+1;
            break;
        }
    }
    if(position==-1){
        printf("%s","����ʧ��");
        return ;
    }
    //���ֲ���(left+right)/2��ֵ����ȡ��
    int left=0,right=length-1,mid;//ע��left��right�ĳ�ʼֵ
    mid=(left+right)/2;
    while (value!=find[mid]){
        if(value<find[mid]){
            right=mid-1;
        }
        if (value>find[mid]){
            left=mid+1;
        }
        mid=(left+right)/2;
        times++;
    }
    printf("%d�ǵ�%d���������Ҵ���Ϊ%d",value,position,times);
}
int main(){
    findValue(14);
    printf("\n");
    findValue(-25);
    printf("\n");
    findValue(121);
    return 0;
}
