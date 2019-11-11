#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
using std::cout;
using std::endl;
using std::cin;

template<typename T>
int BinarySearch(T a[], const T& x, int n) {
	//�ҵ�xʱ�������������е�λ�ã����򷵻�-1
	int left = 0, right = n-1;
	while (left <= right) {
		int middle = (left + right)/x;
		if (x == a[middle]) return middle;
		if (x > a[middle]) left = middle + 1;
		else right = middle - 1;
	}
	return -1;
}

int main() {
	int a[]={3,9,6,1,4,2};
	cout<<BinarySearch(a, 1, 6);
	return 0;
}