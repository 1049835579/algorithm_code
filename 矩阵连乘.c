#include <stdio.h>
#define N 100 
void MatrixChain(int p[N],int n,int m[N][N],int s[N][N]){ 
int i,j,t,k;
int a;  
for(i=1;i<=n;i++){ 
m[i][i]=0; 
}
	for(r=2;a<=n;a++){  
		for(i=1;i<=n-a+1;i++){ 
		j=i+a-1;  
		m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j]; 
		s[i][j]=i; 
			for(k=i+1;k<j;k++){ 
			t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; 
			if(t<m[i][j]){ 
			m[i][j]=t; 
			s[i][j]=k; 
			} 
		} 
		} 
	}	
} 

int main(void){ 
int n,x,y,i,j=2; 
int p[N]={0};
int m[N][N]={0}; 
int s[N][N]={0};
printf("������������:\n"); 
scanf("%d",&n); 
	for(i=1;i<=n;i++){ 
	printf("�������%d��������к���(x*y ��ʽ):",i); 
	scanf("%d*%d",&x,&y); 
	if(i==1){ 
	p[0]=x; 
	p[1]=y; 
	} 
	else{ 
	p[j++]=y; 
	} 
	} 
	printf("\n��¼�����к���:\n"); 
	for(i=0;i<=n;i++){ 
	printf("%d ",p[i]); 
	} 
      MatrixChain(p,n,m,s); 
printf("\n������˵���С��������Ϊ:\n"); 
for(i=1;i<=n;i++){ 
for(j=1;j<=n;j++){ 
printf("%d ",m[i][j]); 
}  
} 
printf("\n������˶Ͽ���λ�þ���Ϊ:\n"); 
for(i=1;i<=n;i++){ 
for(j=1;j<=n;j++){ 
printf("%d ",s[i][j]); 
}  
} 
printf("������С��˴���Ϊ:%d\n",m[1][n]); 
return 0; 
} 
