/*
 * DoublyLinkedList.cpp
 *
 *  Created on: Jan 12, 2018
 *      Author: Tony
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

    // Make the node just added the end of list.
    end = temp;
    // Increase length.
    length++;
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
 * Deconstructor for DoublyLinkedList. Empties the list as soon as program terminates. Big O(n) runtime.
 */
DoublyLinkedList::~DoublyLinkedList()
{
    // Calls make empty method as it handles deleting everything in the list. Garbage management.
    makeEmpty();
}

/**
 * Looks for a user specific number and which node is it located in.
 */
void DoublyLinkedList::searchNumber(int searchItem)
{
    // Make temp equal to start.
    DoublyNode* temp = start;
    // Index starts at 0.
    int nodeIndex = 0;
    // Move through list until we reached the end.
    while (temp != NULL)
    {
        // If the node contains the search number.
        if (temp->data == searchItem)
        {
            cout << searchItem << " is currently located at " << nodeIndex << "node.\n";
        }
        // If we never find the number.
        else
        {
            cout << searchItem << " is not found.\n";
            return;
        }

        // Move on to the next node.
        temp = temp->next;
        // Increase the index.
        nodeIndex++;
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
    temp = temp->previous;
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
