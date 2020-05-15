//
// Created by LuMengLi on 2020/5/14.
//
/**
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 */
//这种解法真是太神奇了
int singleNumber(int* nums, int numsSize){
    int target=0;
    //使用异或运算
    for (int i = 0; i <numsSize ; i++) {
        target^=nums[i];
    }
    return target;
}