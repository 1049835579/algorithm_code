#include <stdio.h>
#define N 20 
void MatrixChain(int p[N],int n,int m[N][N],int s[N][N]){ 
  int i,j,t,k;   
  int r;              
  for(i=1;i<=n;i++){ 
    m[i][i]=0;         //��Խ��� 
  }   
  //���������������ʼһ�ε���  
  for(r=2;r<=n;r++){            //r�Ƕγ�              
    for(i=1;i<=n-r+1;i++){      //i�Ƕ����       
      j=i+r-1;                  //j�Ƕ��յ�     
      m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];  //i������ 
      s[i][j]=i; //��ʼ�� 
      for(k=i+1;k<j;k++){ //��K�����ѣ���������K����� 
        int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; 
        if(t<m[i][j]){ //�����ǰ�������ã��٣�����ˢ�� 
          m[i][j]=t; //m[i][j]��¼ 
          s[i][j]=k; 
        } 
      } 
    } 
  }  
} 
  
int main(void){ 
  int n,n1,m1,i,j=2; //nΪ���������n1Ϊ����������n2Ϊ�������� 
  int p[N]={0};          //�洢������к�������  
  int m[N][N]={0};        //�洢�����������˵���С���� 
  int s[N][N]={0};        //�洢�����������˶Ͽ���λ��  
  printf("������������Ϊ:\n"); 
  scanf("%d",&n); 
  for(i=1;i<=n;i++){ 
    printf("�������%d��������к���(��ʽΪ��n1*m1 ):",i); 
    scanf("%d*%d",&n1,&m1); 
    if(i==1){ 
      p[0]=n1; 
      p[1]=m1; 
    } 
    else{ 
      p[j++]=m1; 
    } 
  } 
  printf("\n��˾�����к���Ϊ:\n"); 
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
  printf("�������С��˴���Ϊ:%d\n",m[1][n]); 
  return 0; 
} 
