//
// Created by LuMengLi on 2020/5/20.
//
/**
 * 给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：
 * 每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。
示例 1：
输入：s = "eleetminicoworoep"
输出：13
解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。
 */
#include <memory.h>
#include <cstring>
#include <cmath>

int ans = 0;
int isOK(int *map){     //0，4，8，14，20分别对应5个元音字母
    if (map[0] % 2 == 0 && map[4] % 2 == 0 &&
        map[8] % 2 == 0 && map[14] % 2 == 0 &&
        map[20] % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}
void left2right(int *map1, int *map2, char *s)
{
    int sLen = strlen(s);
    int left = 0;   //左指针初始指向首位
    int right = sLen - 1;   //右指针初始指向末尾

    while (left <= right) {
        if ((right - left) < (ans - 1)) {   //当左右指针间距小于当前答案时，剪枝
            break;
        }
        while (left <= right) {     //在一轮循环中，右指针固定，移动左指针
            if (isOK(map1) == 1) {      //如果满足条件就更新答案，并跳出本轮，接下来移动右指针进入下一轮
                ans = fmax(ans, right - left + 1);
                break;
            } else {    //左指针不断右移，把字母从统计表中删去
                map1[s[left] - 'a']--;
                left++;
            }
            if ((right - left) < (ans - 1)) {   //当左右指针间距小于当前答案时，剪枝
                break;
            }
        }
        //此时一轮搜索结束，当前右指针所在位置的最长子串已经找到并更新到ans
        //重置左指针指向开头，右指针左移一位；进入下一轮
        left = 0;

        map2[s[right] - 'a']--;
        right--;
        memcpy(map1, map2, sizeof(int)*26);
    }
    return;
}


int findTheLongestSubstring(char * s){
    int map[26] = {0};
    int map1[26] = {0};
    int map2[26] = {0};
    int sLen = strlen(s);

    for (int i = 0; i < sLen; i++) {
        map[s[i] - 'a']++;
    }

    ans = 0;
    memcpy(map1, map, sizeof(int)*26);
    memcpy(map2, map, sizeof(int)*26);
    left2right(map1, map2, s);
    return ans;
}
