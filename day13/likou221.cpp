//
// Created by LuMengLi on 2020/5/8.
//动态规划法
//在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
//dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1
//函数——返回三个数中最小的值
#include <malloc.h>
#include <iostream>
int min(int a,int b,int c){
    printf("%d %d %d\n",a,b,c);
    int m=0;
    if(b>=a && c>=a){
        m=a;
    } else if(a>=b && c>=b ){
        m=b;
    } else if (a>=c && b>=c){
        m=c;
    }
    return m;
}
/**
 *
 * @param matrix 包含0和1值的矩阵
 * @param matrixSize 矩阵的行数
 * @param matrixColSize 矩阵的列数
 * @return
 */
int maximalSquare(char** matrix,int matrixSize, int* matrixColSize){
    int maxSide=0,maxSquare=0;//maxSide用于记录最大正方形的边长;maxSquare表示最大正方形的面积
    if(matrixSize==0||matrixColSize==0){//如果素给矩阵的行和列有一个为0
        // 则即为所求最大正方形的面积即为0
        return maxSide;
    }
    int row=*matrixColSize;
    int dp[matrixSize][row];//定义定义二维数组,dp[i][j]用于存放以matrix[i][j]为右下角的最大正方形的边长。
    for (int i = 0; i <matrixSize ; i++) {
        for (int j = 0; j <row ; j++) {
            if(matrix[i][j]=='1'){//如果matrix[i][j]为0，则dp[i][j]=0
                if(i==0||j==0){//判断特殊的边缘情况
                    dp[i][j]=1;
                }else{
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])+1;
                }
                if(maxSide<dp[i][j]){
                    maxSide=dp[i][j];//比较出最大正方形的边数
                }
            } else{
                dp[i][j]=0;
            }

        }
    }
    maxSquare=maxSide*maxSide;
    return maxSquare;
}
//int main(){
////    char **matrix=(char **)malloc(sizeof(char*)*4);
////    matrix[0]="10100";
////    matrix[1]="10111";
////    matrix[2]="11111";
////    matrix[3]="10010";
////    int a[]={5,5,5,5};
////    int* matrixColSize=a;
////    int area=maximalSquare(matrix,4,matrixColSize);
////    printf("%d\n",area);
////    return 0;
////}