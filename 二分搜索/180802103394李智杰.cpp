#include <Stdio.h> 
#include <iostream>
using namespace std;
#define MAXSIZE 100
template<class Type>
int BinarySearch(Type a[],const Type& x,int n)
{
int left=0; 
int right=n-1;
while(left<=right){
	int middle=(left+right)/2;
	if(x==a[middle])
	return middle;
	if(x>a[right])
	left=middle+1;
	else
	right=middle-1;
}
return-1;
}

int main(){
	int a[MAXSIZE];
	int x,i,length,p;
	 cout<<"�����������С"<<endl;
	cin>>length;
	cout<<"��������������"<<endl;
	for(i=0;i<length;i++){
		cin>>a[i];}
	cout<<"������Ҫ����������"<<endl;	
	 cin>>x;
	p=BinarySearch(a,x,length);
	if(p==-1)
        cout<<"���������ڣ�"<<endl;
    else
    cout<<"�������ڵ�λ��Ϊ��";
    cout<<p+1<<endl;
    
	
}


