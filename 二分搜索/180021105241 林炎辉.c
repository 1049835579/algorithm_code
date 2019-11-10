#include <stdio.h>
BinarySearch(int a[], int n, int key){
    int low = 0;
    int high = n - 1;
    while(low<= high){
        int mid = (low + high)/2;
        int midVal = a[mid];
        if(midVal<key)
            low = mid + 1;
        else if(midVal>key)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
int main(){
    int i,a[100],n,val, ret;//a[100]Ϊ���飬 nΪ���鳤�ȣ� valΪ��Ҫ���ҵ�Ԫ�� �� retΪ�ж��Ƿ���ҳɹ��Ĳ��� 
    printf("���������鳤��n=");
    scanf("%d\n",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
  }
 printf("����Ԫ��Ϊ:");
    for(i=0; i<n; i++)
        printf("%d\t", a[i]);
    printf("\n��������Ҫ���ҵ�Ԫ�أ�");
    scanf("%d",&val);
    ret = BinarySearch(a,i,val);
    if(-1 == ret)
        printf("����ʧ�� \n");
    else
        printf ("���ҳɹ� \n");
    return 0;
}
