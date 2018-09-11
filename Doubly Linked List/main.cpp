// Ayesha Perwaiz
//03-04-2017
//main.cpp

#include "DictEntry.h"
#include "dictionary.h"
#include <fstream>
using namespace std;

int main()
{
    list <DictEntry> myDictionary, WordsToFind; //list<DictEntry> objects
    dictionary wordList; //dictionary object
    wordType words;

    ofstream writeData("revsorted.txt");

    int searchForwardCount = 0, reverseSearchCount = 0; //For number of search comparisons
    string fileInput = "dictionary.txt", findWordsInput = "findwords.txt"; //opens dictionary.txt and findwords.txt file

    //reads words from file
    myDictionary = wordList.wordFile(fileInput);
    WordsToFind = wordList.wordFile(findWordsInput);

    if (myDictionary.begin() == myDictionary.end() || WordsToFind.begin() == WordsToFind.end())
    {
        cout << "Error opening files" << endl;
    }

    else
    {
        //If the files were read successfully

        cout << "Unsorted Dictionary: " << endl;
        wordList.displayList(myDictionary); //displays unsorted dictionary.txt

        myDictionary.sort(); //sorts words in alphabetical order
        cout << endl << "Sorted Dictionary: " << endl;
        wordList.displayList(myDictionary); //displays sorted content

        cout << "\nWords to Find: \n";
        wordList.displayList(WordsToFind); //displays findwords.txt

        //Search for word
        list<DictEntry>::iterator iter = WordsToFind.begin();

        while (iter != WordsToFind.end())
        {
            wordType temp = iter->getWord(); //temp wordType to hold the word
            searchForwardCount = wordList.searchForward(myDictionary, temp);

            if (searchForwardCount == -1)
            {
                //if word was not found in the list
                cout << endl << "Word: " << temp << endl;
                cout << "Not found in the list.\n";
            } //encloses if statement

            else //If word is found in forward search
            {
                cout << "\nWord: " << temp << endl;
                cout << "Number of Forward Searches: " << searchForwardCount << endl; //print searchForward count

                reverseSearchCount = wordList.searchBackward(myDictionary, temp);
                cout << "Number of Reverse Searches: " << reverseSearchCount << endl; //print reverseSearch count
            }
            ++iter;
        } //encloses while loop

        wordList.revPrintList(writeData, myDictionary); //print reverse sorted list to revsorted.txt
    }

    writeData.close(); //close the file opened for output
    return 0;
}