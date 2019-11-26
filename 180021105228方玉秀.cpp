#include <stdio.h>
#define N 20 
void eatrixMultiply(int a[N][N],int b[N][N],int c[N][N],int ra,int ca,int rb,int cb){
	if(ca!=rb)
	   printf("���󲻿ɳ�");
	for(int i=0;i<ra;i++){
		for(int j=0;j<cb;j++){
			int sum=a[i][0]*b[0][j];
			for(int k=1;k<ca;k++)
			sum+=a[i][k]*b[k][j];
			c[i][j]=sum;
		}
	} 

} 
void MatrixChain(int p[N],int n,int m[N][N],int s[N][N]){ 
    for(int i=1;i<=n;i++){ 
    m[i][i]=0;         //��һ���������ʱ����˴���Ϊ 0  
  }   
  //���������������ʼһ�ε���  
    for(int r=2;r<=n;r++){ 
    //��ĳ������ʼ     
    for(int i=1;i<=n-r+1;i++){ 
      //��ĳ������Ľ���  
    int j=i+r-1; 
      //�õ��� i �� j �������˵Ĵ���  
      m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j]; 
      //�õ��������˶Ͽ���λ��  
      s[i][j]=i; 
      //Ѱ�Ҽ����Ų�ͬ���������˴�������Сֵ���޸� m ���飬�ͶϿ���λ�� s ����  
      for(int k=i+1;k<j;k++){ 
        int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; 
        if(t<m[i][j]){ 
          m[i][j]=t; 
          s[i][j]=k; 
        } 
      } 
    } 
  }  
} 
void Traceback(int i,int j,int s[N][N]){
	if(i==j)
	  return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	printf("Multiply A:",i,s[i][j]);
	printf(" A:",i,s[i][j]);
}
int main(void){ 
  int n,n1,m1,i,j=2; 
  int p[N]={0};        
  int m[N][N]={0};        //�洢�����������˵���С���� 
  int s[N][N]={0};        //�洢�����������˶Ͽ���λ��  
  printf("������������:\n"); 
  scanf("%d",&n); 
  for(i=1;i<=n;i++){ 
    printf("�������%d��������к���(n1*m1 ��ʽ):",i); 
    scanf("%d*%d",&n1,&m1); 
    if(i==1){ 
      p[0]=n1; 
      p[1]=m1; 
    } 
    else{ 
      p[j++]=m1; 
    } 
  } 
  printf("\n��¼�����к���:\n"); 
  for(i=0;i<=n;i++){ 
    printf("%d ",p[i]); 
  } 
  printf("\n"); 
  MatrixChain(p,n,m,s); 
  printf("\n������˵���С��������Ϊ:\n"); 
  for(i=1;i<=n;i++){ 
    for(j=1;j<=n;j++){ 
      printf("%d  ",m[i][j]); 
    } 
    printf("\n"); 
  } 
  printf("\n������˶Ͽ���λ�þ���Ϊ:\n"); 
  for(i=1;i<=n;i++){ 
    for(j=1;j<=n;j++){ 
      printf("%d ",s[i][j]); 
    } 
    printf("\n"); 
  } 
  printf("������С��˴���Ϊ:%d\n",m[1][n]); 
  return 0; 
} 
