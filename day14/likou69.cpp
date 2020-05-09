//
// Created by LuMengLi on 2020/5/9.
//
/**实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去**/
#include <math.h>
#include <iostream>
int mySqrt(int x){
    int res= exp(0.5*log(x));
    return ((long long)(res + 1) * (res + 1) <= x ? res+ 1 : res);
}
//int main(){
//    int res=mySqrt(2147395600);
//    printf("%d\n",res);
//    return 0;
//}