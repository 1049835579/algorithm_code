#include<malloc.h>
#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 

#define MAX 100
using namespace std;

int matrix_chain(int *p, int n, int **m, int **s)
{
    //m[][]��С�˴���
    //s[][]��С����ʱ�ĶϿ���
    int i, j, r, k;

    for (i = 0; i < n; i++)   //��һ�������С�˴ζ���Ϊ0
    {
        m[i][i] = 0;
    }

    for (r = 2; r <= n; r++)  //rΪ���˾���ĸ���
    {
        for (i = 0; i <= n - r; i++)   //i��ʾ���˾����еĵ�һ��
        {
            j = i + r - 1;         //j��ʾ���˾����е����һ��
            m[i][j] = 99999;
            for (k = i; k <= j - 1; k++)  //�ڵ�һ�������һ��֮��Ѱ������ʵĶϿ��㣬ע�⣬���Ǵ�i��ʼ����Ҫ�ȼ�����������������˵ĳ˴�
            {
                int tmp = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (tmp < m[i][j])
                {
                    m[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[0][n - 1];
}

/*void print_chain(int i, int j, int **s)
{    //�ݹ�ķ�ʽ������С�����ı��ʽ���

    if (i == j)
    {
        printf("%s", s[i]);
    }
    else
    {
        printf("(");
        print_chain(i, s[i][j], s);
        print_chain(s[i][j] + 1, j, s);
        printf(")");
    }
}*/

void Traceback(int i,int j,int **s){
	if(i==j)
		return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"MultipLy A"<<i<<","<<s[i][j];
	cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl;
}

int main()
{
    //min_part[i][j]�洢����i+1��j+1����С�˴Σ���Ϊ�Ǵ�0��ʼ
    //min_point[i][j]�洢����i+1��j+1֮����С�˴�ʱ�ķָ��
    int *p, **min_part, **min_point;
    /*char *a;*/
    int n = 6, i;
    int ret;

    p = (int *)malloc((n + 1)*sizeof(int));
    /*a = (char *)malloc(6*sizeof(char));*/
    min_part = (int **)malloc(n*sizeof(int *));
    min_point = (int **)malloc(n*sizeof(int *));

    for (i = 0; i < n; i++)
    {
        min_part[i] = (int *)malloc(n*sizeof(int));
        min_point[i] = (int *)malloc(n*sizeof(int));
        /*a[i] = (char *)malloc(n*sizeof(char));*/
    }

    p[0] = 30;   //��һ�����������
    p[1] = 35;     //�ڶ������������
    p[2] = 15;     //����
    p[3] = 5;     //����    
    p[4] = 10;     //����
    p[5] = 20;     //���������������
    p[6] = 25;     //���������������

    /*a[0] = "A1";
    a[1] = "A2";
    a[2] = "A3";
    a[3] = "A4";
    a[4] = "A5";
    a[5] = "A6";*/

    ret = matrix_chain(p, n, min_part, min_point);
    printf("Minest times:%d.\n", ret);
    /*print_chain(0, n - 1, min_point);*/
    
    Traceback(1,6,min_point);

    free(p);
    free(min_part);
    free(min_point);
    /*free(a);*/

    return 0;
}
