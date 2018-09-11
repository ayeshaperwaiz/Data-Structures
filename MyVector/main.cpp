// Ayesha Perwaiz
// main.cpp

#include <iostream>
#include"MyVector.h"
using namespace std;
using namespace HW4;
int main()
{
    MyVector v;
    //Insert elements into vector
    for(int i = 0 ; i < 10 ; i++)
    {
        v.push_back(i);
    }

    cout <<  "Size of Vector is " << v.size() << endl;

    //Check elements at positions
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << "Element at position "<< (i) <<" is " << v[i]<<endl;
        v.push_back(i);
    }

    cout << "Pop back: ";
    v.pop_back();

    return 0;
}
