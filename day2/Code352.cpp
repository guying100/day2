//
// Created by LuMengLi on 2020/4/27.
// 北京理工大学上机题一
//输入:
//前十七位的权值分别是：
//
//W[17]:7 9 10 5 8 4 2 1 6 3 7 9 10 5 8 4 2
//x=(A[0]*W[0]+A[1]*W[1]+A[2]*W[2]+...+A[16]*W[16]) mod 11x和校验位y的对应规则对应如下：
//x:0 1 2 3 4 5 6 7 8 9 10
//y:1 0 x 9 8 7 6 5 4 3 2
//若y等于d则身份证号码正确
//        输出格式：aaaaaabbbbbbbbcccd 正确
//若y不等于d则身份证号码不正确
//        输出格式：应为:aaaaaabbbbbbbbcccy

#include <stdio.h>
int main(){
  char certify[]="52242619811105565x";
  char y[]="10x98765432";
  int w[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2},weight=0;
    for (int i = 0; i <17 ; i++) {
        int data=(int)certify[i]-'0';//将字符串中的值转为数字
        weight=weight+w[i]*data;
    }
    int value=weight%11;
    if(y[value]==certify[17]){
        printf("%s",certify);
        printf("%s","  正确");
    }else{
        printf("%s",certify);
        printf("%s","  不正确");
    }
    return 0;
}