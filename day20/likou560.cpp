//
// Created by LuMengLi on 2020/5/15.
//
/**
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
示例 1 :
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 */
#include <iostream>
int subarraySum(int* nums, int numsSize, int k){
    int count=0,sum;//count用于记录子数组的个数;sum用于记录元素的和
    for (int i = 0; i <numsSize ; i++) {
        sum=nums[i];
        if (sum==k) count++;
        for (int j = i+1; j <numsSize ; j++) {
            sum=sum+nums[j];
            if(sum==k){
                count++;
            }
        }
    }
    return count;
}
//int main(){
//    int nums[]={1,1,1};
//    int count=subarraySum(nums,3,2);
//    printf("%d",count);
//}