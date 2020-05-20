//
// Created by LuMengLi on 2020/5/18.
//
/**
 * 给你一个整数数组 nums ，
 * 请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），
 * 并返回该子数组所对应的乘积。
 */
#include <iostream>
int maxProduct(int *nums, int numsSize) {
    int max = nums[0], index;//max用于选出最大值，index用于求出子数组的乘积
    //个数为1的数组，直接返回那一个元素
    if (numsSize==1){
        return nums[0];
    }
    //选出子数组的最大乘积值
    for (int i = 0; i < numsSize; i++) {
        index=nums[i];
        for (int j = i+1 ; j < numsSize; j++) {
            //比较和转换
            if (max< index) {
                max = index;
            }
            //叠乘
            index=index*nums[j];
        }
        if (index>max){
            max=index;
        }
    }
    return max;
}

//int main() {
//    int nums[] = {2};
//    int res = maxProduct(nums, 2);
//    printf("%d\n",res);
//    return 0;
//}