//
// Created by LuMengLi on 2020/5/7.
//
/**题目：求一个数组A中连续相同数字的和等于s的最长子数组长度.
例如A={1,1,2,1,1,1,2,1}， s=3.则所求子数组长度为 3
要求算法时间复杂度不超过 O(n)，空间复杂度不超过 O(1) .
a) 描述算法思想
        b) 伪代码实现
        c) 计算程序的算法复杂度。 **/
//a)算法思想
/**
 * 首先对于记录变量进行初始化
 * 利用for循环遍历原数组，判断数组中相邻元素是否相同，若相等，
 * sum加上该元素的值，子数组长度加一；若不相等，则表示出现元素
 * 重复相等现象停止，判断重复元素的和是否与target相等，且count+1值大于max，则将count+1值赋给max。
 * max即为所求，返回max。
 */
//b)伪代码实现
/**
 * 初始化count=0,sum=0,max=0
 * for循环遍历原数组
 *    if判断数组相邻元素是否相等
 *       若相等，count++，设置dp[i]默认值
 *       若不相等,判断sum是否与target值相等且count值是否比max值大，
 *       都满足则将count+1=max
 */
//c) 计算程序的算法复杂度
/**
 * 时间复杂度是o(n)
 * 空间复杂度是o(1)
 */
/**
 * 具体代码实现
 * @param nums  所求的数组
 * @param numsSize 所求数组的长度
 * @return
 */
#include <iostream>
int getRepeat(int *nums,int numsSize,int target){
    int count=0,sum=0,max=0;//dp数据用于记录子数组的长度
    //遍历nums的数组的每一个数字
    for (int i = 0; i <numsSize ; i++) {
        if(nums[i]==nums[i+1]){//如果两个数字相等
           count++;//子数组的长度加一
           sum=sum+nums[i];
            if(sum==target && count+1>max){//判断和相等的问题
                max=count;//遇到不相同的情况，将子数组长度
            }
        }else{
            sum=sum+nums[i];
            if(sum==target && count+1>max){//判断和相等的问题
                max=count+1;//遇到不相同的情况，将子数组长度
            }
            sum=0;
            count=0;//将count数组的值设为0
        }
    }

    printf("%d",max);
    return max;
}
int main(){
    int nums[]={1,1,2,5,5,5,5,1},target=10;
    getRepeat(nums,8,target);//函数调用
    return 0;
}




