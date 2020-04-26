//
// Created by LuMengLi on 2020/4/26.
//中南大学上机题三
//

//2 100
//0.7 70
//0.6 50
#include <iostream>
using namespace std;
int main(){
    int n,total,i=0;
    scanf("%d %d",&n,&total);
    float minPrice=0.0;
    float count[n];//折扣率
    int limit[n];//上限
    while(i!=n){
        scanf("%f %d",&count[i],&limit[i]);
        i++;
    }

   //n=1的情况
   if (n==1){
       if(total>limit[0]){
           minPrice=count[0]*limit[0]+total-limit[0];
       }else{
           minPrice=count[0]*limit[0];
       }
   }
   //n>1的情况
   if (n>1){
       //1.需要对所有人的折扣进行排序
       float t=0.0;
       int p=0;
       for(int i=0;i<n;++i){
           for(int j=0;j<n-i-1;++j){
               if(count[j]>count[j+1])
               {
                   t=count[j]; count[j]=count[j+1]; count[j+1]=t;
                   p=limit[j]; limit[j]=limit[j+1]; limit[j+1]=p;
               }

           }
       }
       int totalPrice=limit[0];
       for (int k = 0; k <n ; k++) {
           if(totalPrice<total){
               minPrice=minPrice+count[k]*limit[k];
           }else{
               minPrice=minPrice+count[k]*(limit[k]-totalPrice+total);
               break;
           }
           if(k+1<n){
               totalPrice=totalPrice+limit[k+1];
           }

       }
       if (totalPrice<total){
           minPrice=minPrice+total-totalPrice;
       }
   }
   printf("%1.f",minPrice);
    return 0;
}