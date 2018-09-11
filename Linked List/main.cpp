// Ayesha Perwaiz
// main.cpp
#include "LinkedList.h"
using namespace std;

int main()
{
    char limit[200];
    int line = 0;

    LinkedList list[2]; //list contains two lines

    ifstream inputFile; //stream object
    inputFile.open("input.txt"); //opens text file


    if(!inputFile.is_open())
    {
        //error message will print if file could not be opened
        cout << "Error opening file!";
        return 0;
    }

    while(!inputFile.eof() && line < 2)
    {
        //while not end of file and before list 2 is reached
        inputFile.getline(limit, 200);

        for(int i = 0; limit[i] != '\0'; i++)
        {
            // \0 = NULL
            Node *p = new Node();
            p-> data = limit[i];
            p-> next = NULL;
            list[line].insertAtBack(p);
        }
        line++;
    }

    //displays first line
    cout<<"List 1:";
    list[0].display();

    //displays second line
    cout<< endl << "List 2:";
    list[1].display();

    LinkedList sum = list[0] + list[1];
    LinkedList difference = list[0] - list[1];

    //displays union
    cout<< endl << "List 1 + List 2:";
    sum.display();

    //displays difference
    cout << endl << "List 1 - List 2:";
    difference.display();

}
