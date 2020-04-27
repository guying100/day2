//
// Created by LuMengLi on 2020/4/27.
//北京理工大学上机题二
//二分查找{-36 -25 0 12 14 29 35 47 76 100}，对上述十个数进行二分查找。
//输入样例：
//请输入您要查找的数据：
//14
//-25
//121
//输出样例：
//14是第5个数，查找次数为1。
//-25是第2个数，查找次数为2。
//查找失败。
#include <iostream>
using namespace std;
void findValue(int value){
    int find[]={-36,-25,0,12,14,29,35,47,76,100},length;
    int times=1;//position用于记录value位于第几个数,times记录查找的次数
    length= sizeof(find)/ sizeof(int);//注意求数组的长度的方法
    bool flag= true;//判断是否查找到值,true代表查找到啦
    //二分查找(left+right)/2的值向下取整
    int left=0,right=length-1,mid;//注意left和right的初始值
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
        if (left>=9||right<=1){
           flag= false;
            break;
        }
    }
    if (!flag){
        printf("%s","查找失败");
    }else{
        printf("%d是第%d个数，查找次数为%d",value,mid+1,times);
    }

}
int main(){
    findValue(14);
    printf("\n");
    findValue(-25);
    printf("\n");
    findValue(121);
    return 0;
}
