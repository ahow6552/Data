#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    ~linked_list()
    {
        delete head,tail;
    };

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    int sum_node() 
    {
        long long sum = 0;
        node *tmp = this->head;
        while(tmp != nullptr)
        {
            sum += tmp->data;
            tmp = tmp->next;
        }
        return sum;
    }
};

int main(void){
linked_list a;
int n;

cin >> n;

//Part 1
//auto start = ::chrono::high_resolution_clock::now();

for(long long i = 0; i < pow(2,n); ++i){
    int r = rand()%2;
    a.add_node(r);
}

//Part 2
auto start = ::chrono::high_resolution_clock::now();

long long sum = a.sum_node();

auto finish = ::chrono::high_resolution_clock::now();

cout <<  std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << endl;

return 0;
}
