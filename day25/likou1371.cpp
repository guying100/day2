//
// Created by LuMengLi on 2020/5/20.
//
//有问题：会超过时间限制
#include <string.h>
#include <iostream>
/**
 * 给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：
 * 每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。
示例 1：
输入：s = "eleetminicoworoep"
输出：13
解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。
 */
int* getCount(int* dp,char c){
    switch (c){
        case 'a':
            dp[0]++;
            break;
        case 'e':
            dp[1]++;
            break;
        case 'i':
            dp[2]++;
            break;
        case 'o':
            dp[3]++;
            break;
        case 'u':
            dp[4]++;
            break;
    }
    return dp;
}
int findTheLongestSubstring(char * s){
    //求出字符串的长度
    int len=strlen(s);
    //用于记录5个元音的数量
    int dp[5]={0,0,0,0,0};
    //记录满足条件的最大子字符串
    int max=0,index=0;
    for (int i = 0; i <len ; i++) {
      int* dp1=getCount(dp,s[i]);
        for (int j = i+1; j <len ; j++) {
            int* dp2=getCount(dp1,s[j]);
            if (dp2[0]%2==0&&dp2[1]%2==0 && dp2[2]%2==0 && dp2[3]%2==0&& dp2[4]%2==0){
                index=j-i+1;
//                printf("%d %d %d %d %d\n",dp2[0],dp2[1],dp2[2],dp2[3],dp2[4]);
            }
        }
        if (index>max){
            max=index;
        }
        if (dp1[0]%2==0&&dp1[1]%2==0 && dp1[2]%2==0 && dp1[3]%2==0&& dp1[4]%2==0){
            max=1;
        }
        dp[0]=0;dp[1]=0;dp[2]=0;dp[3]=0;dp[4]=0;
    }
    return max;
}
int main(){
    char * s="id";
    int res=findTheLongestSubstring(s);
    printf("%d",res);
}