//
// Created by LuMengLi on 2020/5/9.
//

#include <stdio.h>
int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}
int getKth(int nums1[], int nums1Size, int nums2[], int nums2Size, int k) {
    //1.确保nums1Size小于nums2Size
    if (nums1Size > nums2Size) {
        return getKth(nums2, nums2Size, nums1, nums1Size, k);
    }
    //2.小数组为空 直接返回
    if (nums1Size == 0) {
        return nums2[k - 1];
    }
    //3.k等于1
    if (k == 1) {
        return min(nums1[0], nums2[0]);
    }
    //4.把问题缩小
    int temp = k / 2-1;
    int i = min(nums1Size - 1, temp);
    int j = min(nums2Size - 1, temp);
    if (nums1[i] < nums2[j]) {
        return getKth(&nums1[i + 1], nums1Size - i - 1, nums2, nums2Size, k - i - 1);
    } else {
        return getKth(nums1, nums1Size, &nums2[j + 1], nums2Size - j - 1, k - j - 1);
    }
}
int main(){
//    int nums1[2] = {1, 2};
//    int nums2[2] = {3, 4};
//    int ret=getKth(nums1,2,nums2,2,4);
    int A[]={1,3,4,5,6};
    int B[]={3,4,5,6};
    int k=8;
    int ret=getKth(A,5,B,4,k);
    printf("%d",ret);
}