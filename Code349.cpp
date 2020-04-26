//
// Created by LuMengLi on 2020/4/26.
//第349题 中南大学上机题一
//
#include <iostream>
using namespace std;
static int MaxLen=1000;
void judge(char *s){
    int E=0,A=0,S=0,Y=0;
    int i=0;
    while (s[i]!=0){
        if (s[i]=='E'){
            E=i;
        }else if(s[i]=='A'){
            A=i;
        }else if(s[i]=='S') {
            S=i;
        }else if(s[i]=='Y'){
            Y=i;
        }
        i++;
    }
    if (E<A&&A<S&&S<Y){
        cout<<"easy"<<endl;
    }else{
        cout<<"difficult"<<endl;
    }
}
//int main()
//{
//    char *s1 = new char[MaxLen],*s2 = new char[MaxLen];
//    scanf("%s", s1);
//    scanf("%s", s2);
//    judge(s1);
//    judge(s2);
//    return 0;
//}
