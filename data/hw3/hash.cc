#include <iostream>
#include <list>
#include <cmath>
#include <chrono>
using namespace std;
const int MAX=pow(2,30);

class HashMapTable
{
// size of the hash table
int table_size;
// Pointer to an array containing the keys
list<int>*table;
int n;
public:
    HashMapTable(int key);
    ~HashMapTable(){
            delete []table;
    };
    // hash function to compute the index using table_size and key
    int hashFunction(int key) {
        return (key % table_size);
    }
    // inserting the key in the hash table
    void insertElement(int key);
    // deleting the key in the hash table
    bool searchElement(int key);
    // displaying the full hash table
    void displayHashTable();
};
//creating the hash table with the given table size
HashMapTable::HashMapTable(int ts)
{
this->table_size = ts;
table = new list<int>[table_size];
}
// insert function to push the keys in hash table
void HashMapTable::insertElement(int key)
{
int index = hashFunction(key);
table[index].push_back(key);
}

// delete function to delete the element from the hash table
bool HashMapTable::searchElement(int key)
{
int index = hashFunction(key);
// finding the key at the computed index
list <int> :: iterator i;
for (i = table[index].begin(); i != table[index].end(); i++)
{
if (*i == key)
break;
}
// removing the key from hash table if found
if (i != table[index].end())
    return 1;
return 0;
}

// Main function
int main()
{
int n;
for(n = 26;n<=30;++n)
{
    double InsertTime = 0;
    double SearchTime = 0;
    int times=10;
    while(--times)
    {
    HashMapTable ht(pow(2,n));
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < pow(2,n); ++i)
    {
        ht.insertElement(rand() % MAX);
    }

    auto end = chrono::high_resolution_clock::now();

    InsertTime += (double)(std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()) ;

    //search
    start = chrono::high_resolution_clock::now();
    int SearchTimes = 100000;
    for(int i = 0; i < SearchTimes; ++i)
    {
        ht.searchElement(rand() % MAX);
    }
    end = chrono::high_resolution_clock::now();
    SearchTime += (double)(std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()) ;
    }
    cout << InsertTime/10000 << " " << SearchTime/10000 << endl << n << " ends" << endl;
}
return 0;
}
