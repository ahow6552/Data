#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

/* This function takes first element as pivot, and places
all the elements smaller than the pivot on the left side
and all the elements greater than the pivot on
the right side. It returns the index of the last element
on the smaller side*/
int partition(int arr[], long long int low, long long int high)
{
    long long int pivot = arr[low];
    long long int i = low - 1, j = high + 1;

	while (true) {
		// Find leftmost element greater than
		// or equal to pivot
		do {
			i++;
		} while (arr[i] < pivot);

		// Find rightmost element smaller than
		// or equal to pivot
		do {
			j--;
		} while (arr[j] > pivot);

		// If two pointers met.
		if (i >= j)
			return j;

		swap(arr[i], arr[j]);
	}
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], long long int low, long long int high)
{
	if (low < high) {
		/* pi is partitioning index, arr[p] is now
		at right place */
		long long int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}

// Driver Code
int main()
{
    int n;
    int counter=0,timeave=0;
    while(cin >> n)
    {
        long long int size = pow(2,n); 
        int *arr=new int[size];
        clock_t start,end;
        for( long long int i = 0; i<size;++i)
            arr[i] = rand()%1000;

        start=clock();
        quickSort(arr, 0, size - 1);
        end=clock();

        delete arr;
        timeave += (end-start)/CLOCKS_PER_SEC;
        if(n==0)
        {
            cout << timeave/counter << endl;
            counter=timeave=0;continue;
        }
        cout << "spend: " << (end-start)/CLOCKS_PER_SEC << endl;
    }
	return 0;
}
