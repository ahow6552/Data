#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
using namespace std;

int main(void) {
long long n;
cin >> n;
n = pow(2,n);
//Part1
//auto start = ::chrono::high_resolution_clock::now();

int *arr1 = new int[n];
for(long long i = 0; i < n; ++i) {
    arr1[i] = rand() % 2;
}
//Part2
int sum = 0;
auto start = ::chrono::high_resolution_clock::now();

for(long long i = 0; i < n; ++i) {
    sum += arr1[i];
}

auto finish = ::chrono::high_resolution_clock::now();
cout <<  std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << endl;
delete [] arr1;
return 0;
}
