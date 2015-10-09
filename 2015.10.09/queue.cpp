#include<iostream>
#include<cassert>
using namespace std;

template <typename T>
class queue{
private:
    T* arr;
    int current;
    int first;
    int size;

public:

    template <typename U>
    friend ostream& operator<<(ostream&, queue<U>&);

//! ne gledai!
//    queue& operator>>(istream& in)
//    {
//        T val;
//        in>>val;
//        push(val);
//        return *this;
//    }

    queue(int s = 20) : size(s), current(0), first(0)
    {
        arr = new T[size];
        assert(arr != NULL);
    }

    ~queue()
    {
        delete [] arr;
    }

    void push(const T what)
    {
        if(size>current){
            arr[(first+current)%size] = what;
            current++;
        } else {
            T* temp = new T[2*size];
            assert(temp != NULL);
            for(int i = 0; i<size; i++){
                temp[i] = arr[(first+i)%size];
            }
            size = 2*size;
            delete [] arr;
            arr = temp;
            arr[current++] = what;
            first = 0;
        }

    }

    T pop ()
    {
        if(!isEmpty()){
            current--;
            if(first==size-1){
                first = 0;
                return arr[size-1];
            }
            return arr[first++];
        }
        cout<<"The queue is empty."<<endl;
        T dummy;
        return dummy;
    }

    bool isEmpty()const
    {
        return current == 0;
    }

    bool print(){
        while(!isEmpty()){
            cout<<pop()<<endl;
        }
    }

};

   template <typename U>
    ostream& operator<<(ostream& out, queue<U>& s)
    {

            out<<s.pop()<<endl;

        return out;
    }



int main()
{
    queue<int> s(3);
//    s>>cin>>cin>>cin;
  s.push(1);
    s.push(2);
    s.push(3);
    cout<<s;
    s.push(4);
    s.push(5);
    s.push(6);
    cout<<s<<s<<s<<s<<s<<s;
    return 0;
}

