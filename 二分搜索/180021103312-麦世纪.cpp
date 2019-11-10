#include <iostream>
using namespace std;
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
int main(void)
{
 int a[10], i, n, flag = 0;
 cout << "����10��������" << endl;
 for (i = 0; i < 10; i++)
  cin >> a[i];
 cout << "����Ҫ���ҵ�����";
 cin >> n;
 for (i = 0; i < 10; i++)
  if (a[i] == n)
  {
   cout << "�����������е��±��ǣ�" << i << endl;
   flag = 1;
   break;
  }
  if (!flag)
   cout << "�޴���" << endl;
  return 0;
}
