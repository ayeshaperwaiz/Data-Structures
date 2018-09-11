// Ayesha Perwaiz
// LinkedList.h

#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

//function definitions and functions under LinkedList class
class LinkedList
{
    Node *start;

public:
    LinkedList()
    {

        start = NULL; //initializes to NULL
    }

    ~LinkedList()
    {
        //destructor to free all nodes

        if(start!=NULL)
        {
            //if start is NULL, list is empty
            Node *current,*q;
            current = start; //current is assigned the value of start

            while(current != NULL)
            {
                q = current-> next; //store the next node address
                delete current; //deletes current node
                current = q;
            }

        } //encloses if statement
    }

    bool insertAtFront(Node *current)
    {
        //inserts node at beginning of list

        if(current == NULL)
        {
            return false;
        }

        if(start == NULL)
        {
            //checks to see if list has start node
            start = current; //current is made current start node
        }

        else
        {
            current-> next = start;
            start = current; //current is the start node
        }

        return true;
    }

    bool insertBeforePosition(int index, Node *current)
    {
        //inserts node before given index position

        if(start == NULL || current == NULL)
        {
            return false;
        }

        else
        {
            Node *indexNode = start, *previous = NULL;
            int i = 1;

            while(i < index && indexNode !=NULL)
            {
                //searches list until index node is reached
                previous = indexNode;
                indexNode = indexNode-> next;
                i++;
            }

            if(indexNode == NULL)
            {
                //if end of list is reached before index position, then return false
                return false;
            }

            else
            {
                current-> next = indexNode; //current points to old index node

                if(previous == NULL)
                    start = current; //inserts at beginning of list
                else
                    previous-> next = current;

                return true;
            }
        } //encloses first else statement
    }

    bool insertAtBack(Node *current)
    {
        //inserts node at the end of list

        if(current == NULL)
        {
            return false;
        }

        if(start == NULL)
        {
            //if nothing is in the list
            start = current; //current is set equal to start
        }
        else
        {
            Node *temp = start;

            while(temp-> next !=NULL)
            {
                //loops until last node in the list
                temp = temp-> next;
            }
            temp-> next = current;

        } //encloses else

        return true;
    }

    bool deleteAtFront()
    {
        //deletes node at front

        if(start == NULL)
        {
            return false;
        }
        else
        {
            Node *current = start;
            start = current-> next; //start of list points to next node
            delete current; //frees up previous start node
        }

        return true;
    }

    bool deleteAtBack()
    {
        //deletes node at back of list

        if(start == NULL)
        {
            return false;
        }
            //frees the last node and updates the last but one node to point to null
        else
        {
            Node *last = start;
            Node *one = NULL; //one node in list
            while(last-> next !=NULL)
            {
                one = last;
                last = last-> next;
            }
            if(one == NULL)
            {
                //if only one node is in the list
                start = NULL; //updates start
            }
            else
            {
                one-> next = NULL;
                delete last;
            }
        }
        return true;
    }


    bool deleteBeforePosition(int index)
    {
        if(start == NULL || index == 1)
        {
            //if list is empty of if its before position 1, return false
            return false;
        }
        else
        {
            Node *previous = start;
            Node *indexNode = previous-> next;
            Node *q = NULL;
            int i = 1;

            while(i < index-1)
            {
                q = previous;
                previous = indexNode;
                indexNode = indexNode-> next;
                i++;
            }

            if(previous == start)
            {
                //if previous node was start node
                start = indexNode; //start is assigned the value of indexNode
            }
            else
            {
                if(q !=NULL)
                {
                    q-> next = indexNode;
                }
            }
            delete previous;

        }
        return true;
    }


    LinkedList operator +(LinkedList &list)
    {
        //implements union of 2 lists

        LinkedList newList;
        Node *current = start, temp;

        while(current !=NULL)
        {

            if(newList.searchData(current-> data)== -1)
            {
                //checks for repeating elements
                Node *q = new Node();
                q-> data = current-> data;
                q-> next = NULL;
                newList.insertAtBack(q);
            }
            current = current-> next;
        }

        //adds elements from second list
        current = list.start;
        while(current !=NULL)
        {
            if(newList.searchData(current-> data) == -1)
            {
                //checks for repeating elements
                Node *q = new Node();
                q-> data = current-> data;
                q-> next = NULL;
                newList.insertAtBack(q);
            }
            current = current-> next;
        }

        return newList;
    }

    int searchData(char data)
    {
        // additional function needed for operator + to remove repeating elements
        // also needed for operator - to search for data
        // returns index position of first occurence

        if(start == NULL)
        {
            return -1;
        }
        else
        {
            Node *q = start;
            int index = 1;
            while(q !=NULL && q-> data !=data)
            {
                q = q-> next;
                index++;
            }

            if(q == NULL)
            {
                //if end is reached without finding repeating elements
                return -1;
            }
            else
                return index;

        }
    }

    LinkedList operator -(LinkedList &list)
    {
        // implements difference of 2 lists
        // elements in list 1 that are not in list 2 will be the result

        LinkedList newList;
        Node *current = start;
        Node *temp;

        while(current !=NULL)
        {
            //add to list if data is not in 2nd list.
            if(list.searchData(current-> data)== -1)
            {
                Node *q = new Node();
                q-> data = current-> data;
                q-> next = NULL;
                newList.insertAtBack(q);
            }
            current = current-> next;
        }
        return newList;
    }

    void display()
    {
        //displays lists
        Node *current = start;
        cout << endl;
        while(current !=NULL)
        {
            cout << current-> data << " ";
            current = current-> next;
        }
        cout << endl;
    }

}; //encloses class
