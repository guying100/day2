//
// Created by LuMengLi on 2020/5/11.
//
/**
 * 你成功以最便宜的价格购买到了偶数只青蛙（青蛙有很多不同的种类），现在要把这些 青蛙平均分给大白与小灰。问小灰能最多获得多少种类的青蛙。
问题简化如下：
输入一个非递减的数组。
输出小灰最多能获得的青蛙种类个数。
函数：int distributeFrog (int nums[ ],int length)
 */
#include<algorithm>
#include <iostream>
int cmp(const void*a,const void*b)
{
    return *(int*)a - *(int*)b;
}
int distributeFrog (int nums[],int length){
    //求出共有多少只青蛙
    int sum=0,k=0;//k用于记录青蛙的种类
    for (int i = 0; i <length ; i++) {
        sum=sum+nums[i];
    }
    //均分小灰可以获得的青蛙数量
    int xFrog=sum/2;

    //对青蛙数组进行排序
    qsort(nums,length, sizeof(int),cmp);
    for (int i = 0; i <length ; i++) {
       if (nums[i]<=xFrog){
           k++;
           xFrog=xFrog-nums[i];
           printf("%d\n",xFrog);
       }
    }
    //如果小灰没有分够
    if (xFrog!=0){
        k++;
    }
    return k;
}
int main(){
    int nums[]={1,6,4,6,3,2};
    int k=distributeFrog(nums,6);
    printf("%d",k);
    return 0;
}