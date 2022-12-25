#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void TWP(int arr[], long long int m, long long int n, long long int &begin, long long int &end)
{
  int pivot = arr[m];
  begin = m, end = n;
  
  for(long long int i = begin + 1 ; i <= end; i++)
  {
    if(arr[i] < pivot)
    {
      swap(arr[i], arr[begin]);
      begin++;
    }
    else if(arr[i] > pivot)
    {
      swap(arr[i], arr[end]);
      end--; 
      i--;
    }
  }
}

void quicksort(int arr[], long long int m, long long int n)
{
  if(m>=n)
  {
    return;
  }
  long long int begin, end;
  TWP(arr, m, n, begin, end);
  quicksort(arr, m, --begin);
  quicksort(arr, ++end, n);
}

int main()
{
    int n;
    int counter = 0;
    int timeave = 0; 
    while(cin >> n)
    {
        long long int size = pow(2,n);
        int *arr = new int[size];
        clock_t start,end;
        for(long long int i = 0; i < size; ++i)
            arr[i] = rand() % 1000;

        start = clock();
        quicksort(arr,0,size-1);
        end = clock();
        
        delete arr;
        timeave += ((end-start)/CLOCKS_PER_SEC);

        if(n == 0)
        {
            cout << timeave/counter << endl;
            timeave = 0;
            counter = 0;
            continue;
        }
        
        counter++;
        cout << "spend: " << (end - start)/CLOCKS_PER_SEC << "times" << endl;
    }
}
