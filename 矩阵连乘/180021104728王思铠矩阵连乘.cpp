#include<iostream>
using namespace std;
const int Max =100;
int p[Max];//����ά��
int m[Max][Max];//����ֵ�����ٳ˷�����
int s[Max][Max];//�Ͽ���λ��
int n;//������� 
 
void MatrixChain(){ //��������ֵ
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int r=2;r<=n;r++){
        for(int i=1;i<=n-r+1;i++){
            int j=r+i-1;
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
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
 
void TrackBack(int i,int j){//���ŷ��� 
    if(i==j) return;
    TrackBack(i,s[i][j]);
    TrackBack(s[i][j]+1,j);
   cout<<"A"<<i<<","<<s[i][j];
   cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl; 
}
int main(){
	cout<<"������Ҫ���Եľ�������͸��������ά����"; 
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>p[i];
	}
	cout<<"���˷���Ϊ��"<<endl; 
	MatrixChain();
	TrackBack(1,n);
	cout<<"����ֵΪ��"; 
	cout<<m[1][n]<<endl;
	return 0;
}
 

