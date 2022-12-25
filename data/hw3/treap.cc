#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>
#include <queue>
using namespace std;

int MAX = pow(2,30);
struct TreapNod  { //node declaration
   int data;
   int priority;
   TreapNod* l, *r;
   TreapNod(int d) { //constructor
      this->data = d;
      this->priority = rand() % 100;
      this->l= this->r = nullptr;
   }
};
void rotLeft(TreapNod* &root) { //left rotation
   TreapNod* R = root->r;
   TreapNod* X = root->r->l;
   R->l = root;
   root->r= X;
   root = R;
}
void rotRight(TreapNod* &root) { //right rotation
   TreapNod* L = root->l;
   TreapNod* Y = root->l->r;
   L->r = root;
   root->l= Y;
   root = L;
}
void insertNod(TreapNod* &root, int d) { //insertion
   if (root == nullptr) {
      root = new TreapNod(d);
      return;
   }
   if (d < root->data) {
      insertNod(root->l, d);
      if (root->l != nullptr && root->l->priority > root->priority)
      rotRight(root);
   } else {
      insertNod(root->r, d);
      if (root->r!= nullptr && root->r->priority > root->priority)
      rotLeft(root);
   }
}
bool searchNod(TreapNod* root, int key) {
   if (root == nullptr)
      return false;
   if (root->data == key)
      return true;
   if (key < root->data)
      return searchNod(root->l, key);
      return searchNod(root->r, key);
}
void deleteNod(TreapNod* &root, int key) {
   //node to be deleted which is a leaf node
   if (root == nullptr)
      return;
   if (key < root->data)
      deleteNod(root->l, key);
   else if (key > root->data)
      deleteNod(root->r, key);
      //node to be deleted which has two children
   else {
      if (root->l ==nullptr && root->r == nullptr) {
         delete root;
         root = nullptr;
      }
      else if (root->l && root->r) {
         if (root->l->priority < root->r->priority) {
            rotLeft(root);
            deleteNod(root->l, key);
         } else {
            rotRight(root);
            deleteNod(root->r, key);
         }
      }
      //node to be deleted has only one child
      else {
         TreapNod* child = (root->l)? root->l: root->r;
         TreapNod* curr = root;
         root = child;
         delete curr;
      }
   }
}

void des(TreapNod *root){
    queue<TreapNod*>q;
    q.push(root);
    while(!q.empty())
    {
        TreapNod* cur = q.front();
        q.pop();
        if(cur->l != NULL)
            q.push(cur->l);
        if(cur->r != NULL)
            q.push(cur->r);
        delete cur;
    }
}
int main(void) 
{
    int n = 27;
    while(n++ <= 30)
    {
        double InsertTime = 0;
        double SearchTime = 0;
        
            TreapNod *root = NULL;
            //insert
            auto start = chrono::high_resolution_clock::now();

            for(int i = 0; i < pow(2,n); ++i)
            {
                insertNod(root, rand() % MAX);
            }
            
            auto end = chrono::high_resolution_clock::now();
                
            InsertTime += (double)(std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()) ; 
            
            //search
            start = chrono::high_resolution_clock::now();
            int SearchTimes = 100000;
            for(int i = 0; i < SearchTimes; ++i)
            {
                searchNod(root,rand() % MAX);
            }
            end = chrono::high_resolution_clock::now();
            SearchTime += (double)(std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()) ;
            des(root);
        
        cout << InsertTime/1000 << " " << SearchTime/1000 << endl << n << " ends" << endl;
    }
    return 0;
}
