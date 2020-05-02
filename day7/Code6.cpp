//
// Created by LuMengLi on 2020/5/2.
//
/**青蛙（frog）杯第一届棒球比赛开赛啦。

你现在是一名记分员，输入一个字符串数组（比赛记录情况），按如下规则计分：

1. 如果该字符串是数字：代表当轮比赛的得分情况。

2. 如果该字符串是“+”： 代表当轮比赛得分情况为上两轮之和。

3. 如果该字符串是“C”： 代表上一轮得分无效。

4. 如果该字符串是“D”:  代表当轮比赛得分为上一轮得分的两倍。

你需要得出最后总的得分情况并返回结果。

函数：int frogPoints(string[ ] ops,int round)  //ops 为字符串数组，round 代表总共的比赛轮数

例子：

输入：

输出：30

解释：

第 1 轮得分 5 分，当前总共得分 5 分。

第 2 轮得分 2 分，当前总共得分 5+2=7 分。

第 3 轮取消上轮得分，当前总共得分 5 分。

第 4 轮获得上一轮双倍得分，当前总共得分 5+10=15 分。

第 5 轮获得上两轮得分之和，当前总共得分 15+5+10=30 分。 **/
#include <iostream>
using namespace std;
int frogPoints(){
    int round=5;
    char ops[]="52CD+";
    int score=0;
    for (int i = 0; i <round ; i++) {
        bool flag= true;
      //如果为+，当前分为前两轮得分之和
      if (ops[i]=='+'){
        ops[i]=(ops[i-1]-'0')+(ops[i-2]-'0')+'0';
      }
      //如果为C，上一轮得分无效
      if (ops[i]=='C'){
          score=score-(ops[i-1]-'0');//减去上一轮无效的分数
          ops[i-1]='0';//将无效的分数置为0，为以后相加做准备
          if (i<2){
              ops[i]='0';
              flag= false;
          } else{
              ops[i]=ops[i-2];
              flag= false;
          }
      }
      //如果为D，获得上一轮双倍得分
      if (ops[i]=='D'){
          ops[i]=2*(ops[i-1]-'0')+'0';
      }
      if (flag){
          score=score+(ops[i]-'0');
      }

    }
    printf("%d\n",score);
}
int main(){
    frogPoints();
    return 0;
}