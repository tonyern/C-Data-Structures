/*
 * DoublyLinkedList.cpp
 *
 *  Created on: Jan 12, 2018
 *      Author: Tony Nguyen
 *      Version: 1.01
 */

#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

/**
 * Default constructor that creates the node. Big O(1) runtime.
 */
DoublyLinkedList::DoublyLinkedList()
{
    // Length is 0 and start is null because there is nothing in the list yet.
    length = 0;
    start = NULL;
    end = NULL;
}

/**
 * Insert new node with data.
 */
void DoublyLinkedList::insertItem(int item)
{
    // S is holder for previous pointer.
    DoublyNode* s = new DoublyNode();
    // Temp is the new node added.
    DoublyNode* temp = new DoublyNode();

    // Add data into temp.
    temp->data = item;
    // Temp next pointer is null.
    temp->next = NULL;

    // If start is null.
    if (start == NULL)
    {
        // Set the previous to null.
        temp->previous = NULL;
        // Set start to point to new node.
        start = temp;
    }
    else
    {
        // Set holder s to start.
        s = start;
        // While there is a node ahead.
        while (s->next != NULL)
        {
            // Set s to equal the next node.
            s = s->next;
        }
        // Set s next pointer to temp node.
        s->next = temp;
        // Set temp node to point back to s.
        temp->previous = s;
    }

    // Make the node just added the end of list for reversing purposes.
    end = temp;
    // Increase length.
    length++;
}

/**
 * This function adds users to add an integer item to the list with a specific index to place it in. Big O(n).
 */
void DoublyLinkedList::insertItem(int item, int positionIndex)
{
    // If there is nothing in list then we can't just add data into a certain position.
    if (start == NULL)
    {
        return;
    }

    // Creating the nodes.
    DoublyNode* temp = new DoublyNode();
    // s node would be the start.
    DoublyNode* s = new DoublyNode();
    // Setting s to start pointer at the beginning of LinkedList.
    s = start;

//    // If inserting item at first position 0.
//    if (positionIndex == 0)
//    {
//        // Setting new node to the value passed in.
//        temp->data = item;
//        // Temp will point to the node start is pointing to.
//        temp->next = start;
//        // Make the next node after temp point back to tmep.
//        start->next->previous = temp;
//        // Start will now point to temp instead.
//        start = temp;
//    }

    // Making sure each element in the list from the beginning to specified position index is not null before adding data.
    for (int i = 0; i < positionIndex - 1; i++)
    {
        s = s->next;
        // If we encounter a null then we cannot add an item in the list.
        if (s == NULL)
        {
            return;
        }
    }

    // Add item to temp node.
    temp->data = item;

    // If adding to the end of list.
    if (s->next == NULL)
    {
        // s next would point to temp.
        s->next = temp;
        // Now make temp point to null since it is the last node in list.
        temp->next = NULL;
        // Make temp point back to s.
        temp->previous = s;
    }
    // All other positions like in between nodes.
    else
    {
        // Temp to point to the next node.
        temp->next = s->next;
        // Make the next node's previous pointer to point back to temp.
        temp->next->previous = temp;
        // The node behind temp is pointing to temp.
        s->next = temp;
        // Temp previous pointer is pointing back to s, node behind temp.
        temp->previous = s;
    }

    // If the item is added to the last position then make it the end node.
    if (temp->next == NULL)
    {
        // Make the node just added the end of list for reversing purposes.
        end = temp;
    }

    // Increase length.
    length++;
}

/**
 * This method allows users to add an array of integers and it would be converted into a link list. Big O(n) runtime.
 */
void DoublyLinkedList::insertAll(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        insertItem(array[i]);
    }
}

/**
 * Delete node and item from DoublyLinkedList specified by user. Big O(n) runtime.
 */
void DoublyLinkedList::deleteItem(int item)
{
    // Create temporary nodes for deletion.
    DoublyNode* temp;
    DoublyNode* targetBetween;
    DoublyNode* targetLast = end;

    // Making sure there is a list of nodes.
    if (start != NULL)
    {
        temp = start;
        // If the item we want to delete is the first node.
        if (item == start->data)
        {
            // Now set the start pointer to the next node.
            start = start->next;
            // Now set the precious pointer which would equal null in this case.
            start->previous = NULL;
            // Delete node temp is pointing to.
            delete temp;
            // Decrease length.
            length--;
        }
        // If the item we want to delete is at the end of the list.
        else if (item == targetLast->data)
        {
            // Make temp equal the end node.
            temp = end;
            // Set the last node to equal the pointer of the previous node.
            targetLast = temp->previous;
            // The end node equals the previous node.
            targetLast->next = temp->next;
            // Now make temp the new end node equal to null.
            temp->next = NULL;
            // Delete node.
            delete targetLast;
            // Decrease length.
            length--;
        }
        // If the item is between two nodes.
        else
        {
            // Another node exist and next data is not the target. Check ahead before navigating to next node.
            while (temp->next != NULL && (!(item == temp->next->data)))
            {
                temp = temp->next;
            }

            targetBetween = temp->next;
            // If target exist.
            if (targetBetween != NULL)
            {
                // Set the next pointer to the node after the one being deleted.
                temp->next = targetBetween->next;
                // Set the next node after the one being deleted to the node before the node being deleted.
                temp->next->previous = temp;
                // Delete the target.
                delete targetBetween;
                // Decrease the length.
                length--;
            }
        }
    }
}

/**
 * Checks if the list is full by seeing if we can add a node in it. Big O(1) runtime.
 */
bool DoublyLinkedList::isFull() const
{
    DoublyNode* location;

    try
    {
        // If we can add a new node with no problem then return false for not full.
        location = new DoublyNode();
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        // It is full so we catch an exception.
        return true;
    }
}

/**
 * Getter for length. Big O(1) runtime.
 */
int DoublyLinkedList::getLength() const
{
    return length;
}

/**
 * Returns the data in the first node but does not remove.
 */
int DoublyLinkedList::peek()
{
    return start->data;
}

/**
 * Returns the data in the last node but does not remove.
 */
int DoublyLinkedList::peekLast()
{
    return end->data;
}

/**
 * Looks at and delete the first node.
 */
int DoublyLinkedList::poll()
{
    int holder = start->data;
    deleteItem(start->data);
    return holder;
}

/**
 * Looks at and delete the last node.
 */
int DoublyLinkedList::pollLast()
{
    // TODO pollLast method not working properly.
    int holder = end->data;
    deleteItem(end->data);
    return holder;
}

/**
 * Empties the list by using pointers. Big O(n) runtime.
 */
void DoublyLinkedList::makeEmpty()
{
    DoublyNode* temp;
    // While there is something in the list.
    while (start != NULL)
    {
        // Set temp to point to the node start is pointing to.
        temp = start;
        // Now change pointer of start to the next node.
        start = start->next;
        // Delete the temp.
        delete temp;
    }
    length = 0;
}

/**
 * Deconstructor for DoublyLinkedList. Empties the list as soon as program terminates to manage memory. Big O(n) runtime.
 */
DoublyLinkedList::~DoublyLinkedList()
{
    // Calls make empty method as it handles deleting everything in the list. Garbage management.
    makeEmpty();
}

/**
 * Looks for a user specific number and which node is it located in. Runtime Big O(n).
 */
void DoublyLinkedList::searchNumber(int searchItem)
{
    // Make temp equal to start.
    DoublyNode* temp = start;
    // Index starts at 1 for counting.
    int nodeIndex = 1;
    // Holder that determines which message to print whether number is found in list or not.
    int holder = 0;
    // Move through list until we reached the end.
    while (temp != NULL)
    {
        // If the node contains the search number.
        if (temp->data == searchItem)
        {
            cout << searchItem << " is currently located in node " << nodeIndex << ".\n";
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
        cout << searchItem << " is not found in list.\n";
    }
}

/**
 * Prints all data in the list using a temp pointer. Big O(n) runtime.
 */
void DoublyLinkedList::forwardShow()
{
    DoublyNode* temp = start;
    // While there is a node in list.
    printf("Forwarding: ");
    while (temp != NULL)
    {
        // Since temp is set to first node print that first node's data.
        printf("%d ", temp->data);
        // Now temp pointer to the next node and it will loop and output until the end of list.
        temp = temp->next;
    }
    printf("\n");
}

/**
 * Prints all data backwards from the end to start. Big O(n) runtime.
 */
void DoublyLinkedList::reverseShow()
{
    DoublyNode* temp = end;
    // While there is a node in list.
    printf("Reversing: ");
    while (temp != NULL && start != NULL)
    {
        // Since temp is set to last node print that last node's data.
        printf("%d ", temp->data);
        // Now temp pointer to the previous node and it will loop and output until the end of list.
        temp = temp->previous;
    }
    printf("\n");
}
