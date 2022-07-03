#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l;
    l.push_front(10);
    l.push_front(32);
    l.push_front(87);
    l.push_front(23);
    l.push_back(65);
    l.push_back(76);
    l.push_back(69);

    cout << l.front() << endl;
    cout << l.back() << endl;

    l.pop_front();
    l.pop_back();
    
    cout << l.front() << endl;
    cout << l.back() << endl;
    return 0;
}