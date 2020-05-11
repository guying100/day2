//
// Created by LuMengLi on 2020/5/11.
//
//实现 pow(x, n) ，即计算 x 的 n 次幂函数
#include <iostream>
double quickMul(double x, long long N) {
    if (N == 0) {
        return 1.0;
    }
    double y = quickMul(x, N / 2);
    return N % 2 == 0 ? y * y : y * y * x;
}
double myPow(double x, int n){
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
}
//int main(){
////    double res=myPow(2.10000,3);
////    printf("%.5f",res);
////    return 0;
////}