#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int insertionSort(int [],long long int);

int main()
{
	int n;
    int count = 0;	
    while(cin >> n)
    {
    int *ptr;
    ++count;
    long long int size = pow(2,n);
	ptr = new int [size];
	for (long long int i = 0; i < size; i++)
	{
		*(ptr + i) = rand() % 1000;
	}

    clock_t start,end;
    start = clock();

	insertionSort(ptr, size);
    
    end = clock();
	cout << (end - start)/CLOCKS_PER_SEC << "  it's : " << count << " times" << endl;
    delete ptr;
    }
	system("pause");
	return 0;
}

int insertionSort(int a[],long long int arraySize)
{
	int temp = 0;
	int next = 0;
	
	for (int i = 1; i < arraySize; i++)
	{
		temp = a[i];//未排序中要拿來排的值
		next = i;//在已排序中最後一個數值的位置

		while ((next>0) && (a[next-1]>temp))//在已排序中的第一個位置要大於零 且 已排序中的值要比 未排序中要拿來比較的值大
		{
			a[next] = a[next - 1];
			next--;
		}

		a[next] = temp;//將未排序中要拿來排的值插入到排序中的元素當中比他小或是等於他的值後面

	}
	return *a;
}
