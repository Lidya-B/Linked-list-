//*****************************************************************************************************
//
//		File:					LDRIVER.cpp
//
//		This program will impliment and test a linked list class that uses nodes to store items.
//	
//		Other files required: 
//			1.	node.h
//          2.  LList.h
//			
//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

#include"node.h"
#include"LList.h"

//*****************************************************************************************************

int main()
{

    llist<int> myLinkedList;

    cout << "Inserting into the list:\n";
    myLinkedList.insert(10);
    myLinkedList.insert(20);
    myLinkedList.insert(15);
    myLinkedList.insert(30);
    myLinkedList.display();
    cout << endl;

    cout << "Number of values in the list: " << myLinkedList.getNumVals() << "\n";
    cout << "\nRemoving and retrieving from the list:\n";
    int dataOut = 0;

    myLinkedList.viewfront(dataOut);
    myLinkedList.remove(dataOut);
    cout << "Removed front. Data removed: " << dataOut << "\n";


    myLinkedList.viewfront(dataOut);
    myLinkedList.retrive(dataOut);
    cout << "Retrieved item from the middle. Data retrieved: " << dataOut << "\n";


    myLinkedList.viewrear(dataOut);
    myLinkedList.remove(dataOut);
    cout << "Removed last item. Data removed: " << dataOut << "\n";
    myLinkedList.display();
    cout << endl;
    cout << endl;


    myLinkedList.remove(dataOut);
    cout << "Attempting to remove a non-existent value: " << dataOut << "\n";
    myLinkedList.retrive(dataOut);
    cout << "Attempting to retrieve a non-existent value: " << dataOut << "\n";

    cout << "Linked List after all removals: ";
    myLinkedList.display();
    cout << endl;
    cout << endl;


    cout << "Number of values in the list: " << myLinkedList.getNumVals() << "\n";

    if (myLinkedList.isempty())
    {
        cout << "The list is empty.\n";
    }
    else
    {
        cout << "The list is not empty.\n";
    }

    if (myLinkedList.isfull())
    {
        cout << "The list is full.\n";
    }
    else
    {
        cout << "The list is not full.\n";
    }

    return 0;
}

//*****************************************************************************************************
