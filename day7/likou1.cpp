//
// Created by LuMengLi on 2020/5/2.
//
#include <cstring>
#include <iostream>
int max(int x,int y){
    if (x>y){
        return x;
    }
    return y;
}
int lengthOfLongestSubstring(char * s){
    int n = strlen(s);//求出字符串的长度
    //字符串为0的时候
    if(!n)
        return 0;
    int dp[n];//用于存放子字符串的长度
    dp[0]=1;
    int m = 1;
    for(int i = 1;i<n;++i)
    {
        int j;
        for(j=i-1;j>=i - dp[i-1];--j)
            if(s[j] == s[i])
                break;
        dp[i] = i-j;
        m = max(m,dp[i]);
    }
    return m;
}

int main(){
    char * s="abcabcbb";
    printf("%d",lengthOfLongestSubstring(s));
    return  0;
}

