#include<stdio.h>

template<class Type> 
int BinarySearch(Type a[],const Type&x,int n){
	int left=0;
	int right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle])
			return middle;
		if(x>a[middle])
			left=middle+1;
		else
			right=middle-1;
	}
	return -1;
}

int main(){
	int *b,n,i;
	int a[10];
	printf("��Ӵ�С����10�����֣�\n");
	for(i=1;i<=10;i++){
		scanf("%d",&a[i-1]);
		printf("\n");
	}
	printf("��������Ҫ���ҵ����֣�\n");
	scanf("%d",&n);
	i=BinarySearch(a,11,6);
	if(-1==i)
		printf("��Ҫ���ҵ����ֲ���������\n");
	else
		printf("��Ҫ���ҵ����ֵ������±�Ϊ%d\n",i);
}
