#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
//��������
void swap(elemType *a,elemType *b){
    elemType temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//˫��ð������
/*�����������潻�����ɨ�衣������ʱ��ǰ����Ƚ���������
�Ĺؼ��֣����������򽻻��������Ĺؼ����ƶ�������β����
ż����ʱ���Ӻ���ǰ�Ƚ����ڹؼ��֣��������򽻻�������С�ؼ����ƶ�������ǰ��*/
void bothway_bubbleSort(elemType a[],int n){
    int low = 0,high = n - 1;
    int flag =  1;                      //һ��������¼Ԫ���Ƿ�������
    while(low < high && flag){          //ѭ��������������flag = 0ʱ˵���Ѿ�û������
        flag = 0;                       //ÿ�˳�ʼ��flagΪ0
        for(int i = low;i < high;i++){  //��ǰ��������
            if(a[i] > a[i + 1]){
                swap(&a[i],&a[i + 1]);
                flag = 1;
            }
        }
        high--;                         //�����Ͻ�
        for(int j = high;j > low;j--){  //�Ӻ���ǰ����
            if(a[j] < a[j - 1]){
                swap(&a[j],&a[j - 1]);
                flag = 1;
            }
        }
        low++;                          //�޸��½�
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
