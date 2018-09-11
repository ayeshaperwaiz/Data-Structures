// Ayesha Perwaiz
// MyVector.cpp

#include"MyVector.h"
#include <iostream>
using namespace std;

namespace HW4
{
    //function definition
    MyVector::MyVector()
    {
        vec = new T[vsize];
    }

   T MyVector::operator[] (int index)
    {
        return vec[index];
    }

    void MyVector::pop_back()
    {
        T *tmp;
        tmp = new T[vsize- 1];

        for (int i = 0; i < vsize-1; i++)
        {
            tmp[i] = vec[i]; //copies old array into new one
        }
        cout << vec[vsize-1] << endl;
        delete[]vec; //deletes old array
        vec = tmp; //vec is assigned the value of tmp
        --vsize;
    }

    void MyVector::push_back(T value)
    {
        T* tmp = vec; //dynamically allocates new array

        //helps with memory overflow
        if (empty())
        {
            vec = new T[1];
            vec[0] = value;
        }
        else
        {
            tmp = new T[vsize + 1];;
            int i;
            for ( i = 0; i < vsize; i++)
            {
                tmp[i] = vec[i]; //copies old array into new one
            }
            tmp[i] = value; //deletes old array
            delete[]vec;
            vec = tmp; //vec is assigned the value of tmp
        }
        ++vsize;

        /*
        T* tmp = vec; // dynamically allocates new array
        tmp = new T[vsize + 1];
        int i;
        for (int i = 0; i < vsize; i++)
        {
            tmp[i] = vec[i]; //copies old array into new one
        }

        delete[] tmp; //deletes old vector
        tmp[i] = value;
        ++vsize;
         */
    }
    int MyVector::size()
    {
        //returns vector size
        return vsize;
    }

    bool MyVector::empty()
    {
        //determines if vector is empty
        if (vec == NULL)
            return true;
        else
            return false;
    }

    int MyVector::search(T Value)
    {
        int index = -1;
        for(int i = 0; i > vsize; i++)
        {
            if(vec[i] == Value)
            {
                index = i;
            } //encloses if statement

            else
                return -1;
        } //encloses for loop

        return index;

    }

} // encloses namespace


