#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    //parametrized constructor
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

int main()
{
    node n1(5); //n1 will be the object type of node
    node n2(7); //n2 will be the object type of node

    n1.next = &n2;

    // cout << &n1 << endl;     //poore n1 bucket ka address
    // cout << &n2 << endl;     //poore n2 bucket ka address

    cout << "Data of n1 is : " << n1.data << endl;
    cout << "Data of n2 using n1 is : " << (*n1.next).data << endl; //is equal to cout<<"Data of n2 using n1 is : "<<n2.data<<endl;
    cout << "Data of n2 using n1 is : " << n1.next->data << endl;   //without derefrence


    return 0;
}