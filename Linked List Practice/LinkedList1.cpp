#include <iostream>
using namespace std;

class node
{
public:
        int data;
        node *next;

        // constructor
        node(int d)
        {
                data = d;
                next = NULL;
        }
};

int main()
{
        node n1(5); // n1 will be the oject type of node
        node n2(6); // n2 will be the oject type of node
        n1.next = &n2;
        cout << " Data in n1 is " << n1.data << " data in n2 by using n1 is " << (*n1.next).data << endl;
        cout << " Data in n1 is " << n1.data << " data in n2 by using n1 thorugh pointer  " << n1.next->data << endl;

        return 0;
}