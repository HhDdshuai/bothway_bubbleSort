#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
//交换函数
void swap(elemType *a,elemType *b){
    elemType temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//双向冒泡排序
/*在正反两方面交替进行扫描。奇数趟时从前往后比较相邻语素
的关键字，遇到逆序则交换，把最大的关键字移动到序列尾部。
偶数趟时，从后往前比较相邻关键字，遇到逆序交换，把最小关键字移动到序列前端*/
void bothway_bubbleSort(elemType a[],int n){
    int low = 0,high = n - 1;
    int flag =  1;                      //一趟排序后记录元素是否发生交换
    while(low < high && flag){          //循环跳出条件，当flag = 0时说明已经没有逆序
        flag = 0;                       //每趟初始化flag为0
        for(int i = low;i < high;i++){  //从前往后起泡
            if(a[i] > a[i + 1]){
                swap(&a[i],&a[i + 1]);
                flag = 1;
            }
        }
        high--;                         //更新上界
        for(int j = high;j > low;j--){  //从后往前起泡
            if(a[j] < a[j - 1]){
                swap(&a[j],&a[j - 1]);
                flag = 1;
            }
        }
        low++;                          //修改下界
    }
}
int main()
{
    elemType a[] = {17,689,941,365,756,45,75,12,13,19,28,26,46,
    43,37,98,67,61,06,07,102,961,231};
    int len = sizeof(a)/sizeof(elemType);
    bothway_bubbleSort(a,len);
    for(int i = 0;i < len;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
