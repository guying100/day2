//
// Created by LuMengLi on 2020/5/1.
//
//在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
//但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
//
//例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
//各位小皮皮有什么好的解法呢？(子向量的长度至少是1)
#include <iostream>
int maxSubArray(int array[],int length){
    int sum=0;
    int ret=array[0];
//dp代表前n项和 则dp[j+1]-dp[i]为第i到j项和
    int dp[length+1];
    dp[0]=0;
    for(int i=1;i<=length;i++){
        dp[i]=dp[i-1]+array[i-1];
    }
    for(int i=0;i<length;i++){
        for(int j=i;j<length;j++){
            if(dp[j+1]-dp[i]>ret){
                ret=dp[j+1]-dp[i];
            }
        }
    }
    return ret;
}
int main(){
    int a[]={-2,1,-3,4,-1,2,1,-5,4};
    int sum=maxSubArray(a,9);
    printf("%d",sum);
}
