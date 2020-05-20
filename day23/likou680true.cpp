//
// Created by LuMengLi on 2020/5/19.
//
#include <string.h>

/**
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
   示例 1:
   输入: "aba"
   输出: True
 */
bool palindrome(char* s, int i, int j)
{
    for ( ; i < j && s[i] == s[j]; ++i, --j);
    return i >= j;
}

bool validPalindrome(char* s) {
    int i = 0, j = strlen(s) - 1;
    for ( ; i < j && s[i] == s[j]; ++i, --j);
    return palindrome(s, i, j - 1) || palindrome(s, i + 1, j);
}
