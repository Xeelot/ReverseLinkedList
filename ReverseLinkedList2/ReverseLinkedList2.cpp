// ReverseLinkedList2.cpp : Defines the entry point for the console application.
//

#include <cstdlib>
#include <iostream>
#include <string>


class Node
{
public:
   Node(int val) { value = val; next = NULL; }
   ~Node() {}
   int value;
   Node *next;
};


class LinkedList
{
public:
   LinkedList() { head = NULL; }
   ~LinkedList() {}
   void addNode(int value);
   void displayList();
   void reverseList();

private:
   Node *head;
};


void LinkedList::addNode(int value)
{
   Node *temp;
   if (head == NULL)
   {
      // Initialize the head and exit
      head = new Node(value);
      return;
   }
   else
   {
      // Set a temp pointer to the head to search for the end of the linked list
      temp = head;
   }
   // Continue moving the pointer until you reach the end of the list (NULL)
   while (temp->next != NULL)
   {
      temp = temp->next;
   }
   // Create a new node at the end of the list
   temp->next = new Node(value);
}


void LinkedList::displayList()
{
   Node *temp = head;
   std::cout << "List: ";
   // Loop through the list printing each value until the end is reached
   while (temp != NULL)
   {
      std::cout << temp->value << " ";
      temp = temp->next;
   }
   std::cout << std::endl;
}


void LinkedList::reverseList()
{
   // [0]->[1]->[2]->NULL
   //      [1]->[2]->NULL             [0]->NULL
   //           [2]->NULL        [1]->[0]->NULL
   //                NULL   [2]->[1]->[0]->NULL
   Node *nodeToMovePtr = head;
   Node *nodeAfterMovePtr = NULL;
   Node *nodeBeforeMovePtr = NULL;

   // Loop over the linked list moving pointer to reverse the list
   while (nodeToMovePtr != NULL)
   {
      nodeAfterMovePtr = nodeToMovePtr->next;
      nodeToMovePtr->next = nodeBeforeMovePtr;
      nodeBeforeMovePtr = nodeToMovePtr;
      nodeToMovePtr = nodeAfterMovePtr;
   }
   // Reset the head pointer after reversing;
   head = nodeBeforeMovePtr;
}


int main()
{
   LinkedList list;
   for (int i = 0; i < 6; ++i)
   {
      list.addNode(i);
   }
   list.displayList();
   list.reverseList();
   list.displayList();
   list.addNode(10);
   list.displayList();
   list.reverseList();
   list.displayList();
   system("PAUSE");
    return 0;
}

