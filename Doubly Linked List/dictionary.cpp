// Ayesha Perwaiz
// 03-03-2017
// dictionary.cpp

#include "dictionary.h"
#include <fstream>
using namespace std;

dictionary::dictionary()
{
    // default constructor
}

list<DictEntry> dictionary::wordFile(string fileName)
{
    string dataFile = fileName;
    ifstream readData(dataFile); //open fileName to read from the file

    list<DictEntry> myList; //List of DictEntry types
    wordType wordT;

    if (readData) //If file is opened successfully add contents to a list
    {
        while (readData >> wordT) //continue loop until there are no more words to read in the file
        {
            DictEntry* newEntry = new DictEntry; //allocate memory for a dictionary entry
            newEntry->setWord(wordT);   //set the newEntry to the wordType variable wordT value

            myList.push_back(*newEntry); //dereference the newEntry and add to the end of myList
        }
    }
    else //If file does not open correctly, display fileName and error message
        cout << "Error opening file: " << fileName << endl;

    readData.close(); //close file
    return myList; //return list of words from the given file
}

int dictionary::searchForward(list<DictEntry> &wordList, wordType &findString)
{
    // defines method to search words from beginning of list

    bool found = false; //declaration of boolean
    int numberOfSearch = 0; //variable to count number of searches
    list<DictEntry>::iterator iter; //iterator

    for (iter = wordList.begin(); iter != wordList.end(); ++iter)
    {
        numberOfSearch++; //increments number of searches

        if (iter->getWord() == findString)
        {
            found = true; //found true
            break;
        }
    } //encloses for loop

    if (found)
        return numberOfSearch; //returns number of searches

    else
        return -1;
}

int dictionary::searchBackward(list<DictEntry> &wordList, wordType &findString)
{
    // defines method to search words from end of list

    bool found = false; //declaration of boolean
    int numberOfSearch = 0;  //variable to count number of searches
    list<DictEntry>::reverse_iterator iter; //reverse iterator


    for (iter = wordList.rbegin(); iter != wordList.rend(); ++iter)
    {
        // Increment number of searches

        numberOfSearch++; //increments number of searches

        if (iter->getWord() == findString)
        {
            found = true; //found true
            break;
        }
    } //encloses for loop

    // If word is found in the file

    if (found)
        return numberOfSearch; //returns number of searches

    else
        return -1;
}

void dictionary::revPrintList(ostream& output, list<DictEntry> &wordList)
{
    //prints list in reverse alphabetical order

    list<DictEntry>::reverse_iterator iter; //reverse iterator

    for (iter = wordList.rbegin(); iter != wordList.rend(); ++iter)
    {
        output << iter->getWord() << " "; //writes to file
        cout << iter->getWord() << " "; //displays
    } //encloses for loop
}

void dictionary::displayList(list<DictEntry> &wordList)
{
    //function for displaying words

    list<DictEntry>::iterator iter;

    for (iter = wordList.begin(); iter != wordList.end(); ++iter)
    {
        cout << iter->getWord() << " ";
    }

    cout << endl;
}