#include <stdio.h>
int BinarySearch(int x,int a[],int n)
{
    int left,right,middle,count=0,count1=0;
    left=0;
    right=n-1;
    while(left<right)    //���ҷ�Χ��Ϊ0ʱִ��ѭ�������
    {
        count++;    //count��¼���Ҵ���
        middle=(left+right)/2;    
        if(x<a[middle])   
            right=middle-1;   
        else if(x>a[middle])
            left=middle+1;
        else if(x==a[middle])    //��key�����м�ֵʱ��֤�����ҳɹ�
        {
            printf("find it!\n search %d times !a[%d]=%d",count,middle,x);    //������Ҵ�����������Ԫ���������е�λ��
            count1++;    //count1��¼���ҳɹ�����
            break;
        }
    }
    if(count1==0)    //�ж��Ƿ����ʧ��
        printf("search default!");    //����ʧ�����no found
    return 0;
}
int main()
{
    int i,x,a[100],n;
    printf("please input the array.length:\n");
    scanf("%d",&n);    //��������Ԫ�ظ���
    printf("please input array element:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);    //�����������е�����a��
    printf("please input you want to search the element:\n");
    scanf("%d",&x);    //����Ҫ^�ҵĹؼ���
    BinarySearch(x,a,n);    //�����Զ��庯��
    printf("\n");
    return 0;
}
