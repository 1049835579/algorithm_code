
	#include <iostream> 
	#include<stdlib.h>      
	using namespace std;   
	  
	template<class Type>  
	int BinarySearch(Type a[],const Type& x,int n);  
	  
	int main()  
	{  
	    int x = 69;  
	    int a[70];  
	    for(int i=0; i<70; i++)  
	    {  
	        a[i]=i+1;  
	    }  
	    for(int i=0; i<70; i++)  
	    {  
	        cout<<a[i]<<" ";  
	    } 
	    cout<<endl;
	    
	    cout<<"������������"<<x<<"��λ���±�Ϊ:";  
	    cout<<BinarySearch(a,x,70)<<endl;  
	    system("pause");
		return 0;  
	}  
	  
	template<class Type>  
	int BinarySearch(Type a[],const Type& x,int n)  
	{  		//��a[0]<=a[1]<=a[n-1]������x,�ҵ�xʱ�������������е�λ�ã����򷵻�-1 
	    int left = 0;  
	    int right = n-1;  
	    while(left<=right)  
	    {  
	        int mid = (left + right)/2;  
	        if(x == a[mid])  
	        {  
	            return mid;  
	        }  
	        if(x>a[mid])  
            {  
	            left = mid + 1;  
	        }  
            else  
	        {  
	            right = mid - 1;  
	        }  
       }  
	  
    return -1;  //δ�ҵ�x 
   }  

