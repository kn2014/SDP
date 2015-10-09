#include<iostream>
#include<cassert>
#include<cstdlib>
using namespace std;

template <typename T>
struct node
{
    T inf;
    node<T>* link;

    node() : link(NULL) {}
    node(T what) : inf(what), link(NULL) {}
};

template <typename T>
class queue
{
private:
    node<T>* first;
    node<T>* current;
    node<T>* last;
    unsigned size;

public:
    queue()
    {
        first = NULL;
        current = NULL;
        last = NULL;
        size = 0;
    }

    ~queue()
    {
        current = first;
        while(current != NULL){
            node<T>* temp = current;
//            cout<<"delete "<<temp->inf<<endl;
            current = temp->link;
            delete temp;
        }
    }

    void push(const T what)
    {
        if(size == 0)
        {

            first = new node<T>(what);
            last = first;
            size++;
        }
        else
        {


        node<T>* temp = new node<T>(what);
        last->link = temp;
        last = temp;
        size++;
        }
    }


    T pop()
    {
        T val = first->inf;
        node<T>* old = first;
        first = first->link;
        delete old;
        size--;
        return val;

    }

    void print()
    {
        current = first;
        while(current)
        {
            cout<<current->inf<<endl;
            current = current->link;
        }
    }
};

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop();
    cout<<q.pop();
    cout<<q.pop();
    //q.print();
return 0;
}
