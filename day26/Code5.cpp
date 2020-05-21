//
// Created by LuMengLi on 2020/5/21.
//
#include <string.h>
#include <malloc.h>
/**
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 */
int isTrue(char *s){
    int len = strlen(s);
    int i,j = len - 1;
    for(i = 0;i < len / 2;i++){
        if(s[i] != s[j]){
            return 0;
        }
        j--;
    }
    return 1;
}
char * longestPalindrome(char * s){
    if(s[0] == '\0')
        return s;
    int len = strlen(s);
    int **dp = (int **)malloc(sizeof(int *) * (len + 1));
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(res, s);
    int i,j,n;
    for(i = 0;i <= len; i++){
        dp[i] = (int *)malloc(sizeof(int) * (len + 1));
        memset(dp[i], 0, sizeof(int) * (len + 1));
    }
    for(i = 0,j = 0;i <= len;i++,j++){
        dp[i][j] = 1;
    }
    for(i = 0,j = 1;j<=len;i++,j++){
        if(s[i] == s[j])
            dp[i][j] = 1;
    }
    for(n = 2;n <= len;n++){
        for(i = 0,j = n;j<=len;i++,j++){
            if(dp[i + 1][j - 1] == 1 && s[i] == s[j])
                //printf("i is %d\tj is %d\n",i,j);
                dp[i][j] = 1;
        }
    }
    int start = 0,end = 0;
    for(i = 0;i <= len;i++){
        for(j = i;j <= len;j++){
            if(dp[i][j] == 1 && (j - i) > (end - start) ){
                //printf("i is %d\tj is %d\n",i,j);
                start = i;
                end = j;
            }
        }
    }
    //printf("the start is %d\n,the end is %d\n",start,end);
    if(end <= len){
        res[end + 1] = '\0';
    }
    while(start > 0){
        res++;
        start--;
    }

    return res;

}