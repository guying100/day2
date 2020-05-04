//
// Created by LuMengLi on 2020/5/4.
//
//[3,4,-1,1]
#include <iostream>
int firstMissingPositive(int* nums, int numsSize){
    //正数数组的长度为0
    if (numsSize==0){
        return 1;
    }
   //对nums数组中的正数排序
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize - i -1; j++) {   // 这里说明为什么需要-1
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    if (nums[0]>=2 || nums[numsSize-1]<0){
        return 1;
    }
    for (int k = 0; k <numsSize-1 ; ++k) {
        if(nums[k]>0 && (nums[k]+1)<nums[k+1]){
            return nums[k]+1;
        }
        if (nums[k]<0 &&nums[k+1]>1){
            return 1;
        }
    }
    return nums[numsSize-1]+1;
}
int main(){
    int num[]={7,8,9,11,12};
    int result=firstMissingPositive(num,5);
    printf("%d",result);
    return 0;
}