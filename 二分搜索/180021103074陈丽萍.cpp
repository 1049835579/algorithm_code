//���η���������� 
#include<stdio.h>
template<class Type>
int BinarySearch(Type a[],const Type& x, int n){
	int left=0;
	int right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle]){
			printf("�������λ�õ�%d��\n",middle+1);break;
		}
		else{
			if(x>a[middle])
			    left=middle+1;
		    else
				right=middle-1;
		}	
	}
	if(left>right)
		printf("û���ҵ������\n");
}
int main(){
	int i,n,x;
	printf("������5�����������\n");
	int a[5];
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	printf("������Ҫ���ҵ���\n");
	scanf("%d",&x);
	BinarySearch(a,x,5);
	return 0;
}
