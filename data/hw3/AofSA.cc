#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=pow(2,30);

class array_of_sorted_arrays{
	public:
		array_of_sorted_arrays();
		void insert(int);
		bool search(int) const;
		vector<int> merge(const vector<int>&, const vector<int>&) const;
		vector<vector<int>>& getV() {return v;}
	private:
		int usage;
		vector<vector<int>> v;
};

array_of_sorted_arrays::array_of_sorted_arrays(){
	usage = 0;
	v.resize(31);
}

void array_of_sorted_arrays::insert(int num){
	vector<int> tmp;
	tmp.push_back(num);
	for(int i = 0;i <= 30;++i){
		if(usage & 1 << i){  //judge if array i has used, if used then merge
			tmp = merge(v[i], tmp);
			usage &= ~(1 << i); 
			v[i].clear();
		}
		else{ // if i not used, just insert the array.
			v[i] = tmp;
			usage |= 1 << i;
			break;
		}
	}
}

bool array_of_sorted_arrays::search(int target) const{
	for(int i = 0;i <= 30;++i){ // use binary_search to search every sorted_arrays
		if(binary_search(v[i].begin(), v[i].end(), target))
			return true;
	}
	return false;
}

/*int binary_search(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}*/

vector<int> array_of_sorted_arrays::merge(const vector<int>& v1, const vector<int>&v2) const{
	vector<int> v;
	int x = 0, y = 0;
	if(v1.size()!= v2.size()){ //default debuger
		cout << "v1 and v2 size are diff" << endl;
		exit(0);
	}
	while(1){ //merge to sorted_arrays
		if(x < v1.size() && y < v2.size()){
			if(v1[x] < v2[y])
				v.push_back(v1[x++]);
			else
				v.push_back(v2[y++]);
		}
		else if(x < v1.size()){
			v.push_back(v1[x++]);
		}
		else if(y < v2.size()){
			v.push_back(v2[y++]);
		}
		else{
			break;
		}
	}
	return v;
}

int main()
{
for(int n = 10;n <= 30;++n){
    int times = 10;
    double InsertTime=0;
    double SearchTime=0;
    while(times--)
    {
    array_of_sorted_arrays a;
     auto start = chrono::high_resolution_clock::now();
     for(int i = 0; i < pow(2,n); ++i)
     {
         a.insert(rand() % MAX);
     }

     auto end = chrono::high_resolution_clock::now();

     InsertTime += (double)(std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()) ;

     //search
     start = chrono::high_resolution_clock::now();
     int SearchTimes = 100000;
     for(int i = 0; i < SearchTimes; ++i)
     {
         a.search(rand() % MAX);
     }
     end = chrono::high_resolution_clock::now();
     SearchTime += (double)(std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()) ;
     }
     cout << InsertTime/10000 << " " << SearchTime/10000 << endl << n << " ends" << endl;
}
return 0;
}
