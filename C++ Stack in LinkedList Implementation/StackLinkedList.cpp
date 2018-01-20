/*
 * StackLinkedList.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: Tony Nguyen
 */

#include <iostream>
#include "StackLinkedList.h"
using namespace std;

/**
 * Default constructor creating the empty stack.
 */
StackLinkedList::StackLinkedList()
{
    // There is nothing in stack when constructor is first created.
    head = NULL;
    length = 0;
}

/**
 * Function that adds items to the stack. Big O(1).
 */
void StackLinkedList::push(int item)
{
    // Create a new node.
    StackNode* temp = new StackNode();
    // Putting item into new node.
    temp->data = item;
    // Setting next pointer to head which is null when list is empty at first.
    temp->next = head;
    // Setting head pointer to next instead of null.
    head = temp;
    // Increase length because we increase node list.
    length++;
}

/**
 * Removes value from top of stack every time it is called. Big O(1).
 */
int StackLinkedList::pop()
{
    StackNode* temp;
    int holder;

    // Making sure list is not empty so we can pop values from list.
    if (head != NULL)
    {
        // Make temp be the node in the top.
        temp = head;
        // Storing value that is to be deleted to return to the user what value is deleted.
        holder = temp->data;
        // Now make head point to the next node after top.
        head = head->next;
        // Delete the node.
        delete temp;
    }
    // Decrease stack size.
    length--;
    return holder;
}

/**
 * Returns length of the stack. Big O(1).
 */
int StackLinkedList::getLength()
{
    return length;
}

/**
 * Looks at the current top value of stack without removing it.
 */
int StackLinkedList::peek()
{
    return head->data;
}

/**
 * Checking if the stack contains nodes or not. Big O(1).
 */
bool StackLinkedList::empty()
{
    // If the head is pointing to null then stack is empty.
    if (head == NULL)
    {
        return true;
    }
    // Otherwise then it is not empty.
    else
    {
        return false;
    }
}

/**
 * Looks for a user specific number and which node is it located in. Runtime Big O(n).
 */
void StackLinkedList::search(int searchNumber)
{
    // Make temp equal to start.
    StackNode* temp = head;
    // Index starts at 1 for counting.
    int nodeIndex = 1;
    // Holder that determines which message to print whether number is found in list or not.
    int holder = 0;
    // Move through list until we reached the end.
    while (temp != NULL)
    {
        // If the node contains the search number.
        if (temp->data == searchNumber)
        {
            cout << searchNumber << " is currently located in node " << nodeIndex << ".\n";
            holder = 1;
            break;
        }

        // Move on to the next node.
        temp = temp->next;
        // Increase the index.
        nodeIndex++;
    }
    // If search number not found in list then let the user know.
    if (holder == 0)
    {
        cout << searchNumber << " is not found in list.\n";
    }
}

/**
 * Prints all data in the list using a temp pointer. Big O(n) runtime.
 */
void StackLinkedList::forwardShow()
{
    StackNode* temp = head;
    // While there is a node in list.
    printf("Forwarding: ");
    while (temp != NULL)
    {
        // Since temp is set to first node print that first node's data.
        printf("%d -> ", temp->data);
        // Now temp pointer to the next node and it will loop and output until the end of list.
        temp = temp->next;
    }
    printf("\n");
}

/**
 * Empties the list by using pointers. Big O(n) runtime.
 */
void StackLinkedList::makeEmpty()
{
    StackNode* temp;
    // While there is something in the list.
    while (head != NULL)
    {
        // Set temp to point to the node start is pointing to.
        temp = head;
        // Now change pointer of start to the next node.
        head = head->next;
        // Delete the temp.
        delete temp;
    }
    length = 0;
}

/**
 * Emptying the program for memory management purposes. Big O(1).
 */
StackLinkedList::~StackLinkedList()
{
    makeEmpty();
}
