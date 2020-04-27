//
// Created by LuMengLi on 2020/4/27.
// ��������ѧ�ϻ���һ
//����:
//ǰʮ��λ��Ȩֵ�ֱ��ǣ�
//
//W[17]:7 9 10 5 8 4 2 1 6 3 7 9 10 5 8 4 2
//x=(A[0]*W[0]+A[1]*W[1]+A[2]*W[2]+...+A[16]*W[16]) mod 11x��У��λy�Ķ�Ӧ�����Ӧ���£�
//x:0 1 2 3 4 5 6 7 8 9 10
//y:1 0 x 9 8 7 6 5 4 3 2
//��y����d�����֤������ȷ
//        �����ʽ��aaaaaabbbbbbbbcccd ��ȷ
//��y������d�����֤���벻��ȷ
//        �����ʽ��ӦΪ:aaaaaabbbbbbbbcccy

#include <stdio.h>
int main(){
  char certify[]="52242619811105565x";
  char y[]="10x98765432";
  int w[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2},weight=0;
    for (int i = 0; i <17 ; i++) {
        int data=(int)certify[i]-'0';//���ַ����е�ֵתΪ����
        weight=weight+w[i]*data;
    }
    int value=weight%11;
    if(y[value]==certify[17]){
        printf("%s",certify);
        printf("%s","  ��ȷ");
    }else{
        printf("%s",certify);
        printf("%s","  ����ȷ");
    }
    return 0;
}