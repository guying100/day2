//
// Created by LuMengLi on 2020/5/7.
//
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
#include <iostream>
int* twoSum(int* nums, int numsSize, int target,int* returnSize){
    int *list = (int*)malloc(sizeof(int) * 2);
    list[0]=0;list[1]=0;
    for (int i = 0; i <numsSize-1 ; i++) {
        for (int j = i+1; j <numsSize; j++) {
            if (nums[i]+nums[j]==target){
                list[0]=i;
                list[1]=j;
                *returnSize=2;
                break;
            }
        }

    }
    return list;
}
//int main(){
//    int nums[]={2, 7, 11, 15},returnSize[2];
//    int target=18;
//    twoSum(nums,4,target,returnSize);
//    return 0;
//}