/*
 * LinkedList.cpp
 *
 *  Created on: Jan 9, 2018
 *      Author: Tony
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;

/**
 * Default constructor. Big O(1) runtime.
 */
LinkedList::LinkedList()
{
    // Empty list. No node exist yet.
    length = 0;
    start = NULL;
}

/**
 * We insert item into the node in front of the list. Big O(1) runtime.
 */
void LinkedList::insertItem(int item)
{
    // Create a new node.
    Node* temp = new Node();
    // Putting item into new node.
    temp->data = item;
    // Setting next pointer to start which is null when list is empty at first.
    temp->next = start;
    // Setting start pointer to next instead of null.
    start = temp;
    // Increase length because we increase node list.
    length++;
}

/**
 * Delete node and item from LinkedList specified by user. Big O(n) runtime.
 */
void LinkedList::deleteItem(int item)
{
    // Making sure there is a list of nodes.
    if (start != NULL)
    {
        Node* temp = start;
        // If the item we want to delete is the first node.
        if (item == start->data)
        {
            // Now set the start pointer to the next node.
            start = start->next;
            // Delete node temp is pointing to.
            delete temp;
            // Decrease length.
            length--;

        } else {
            // Another node exist and next data is not the target. Check ahead before navigating to next node.
            while (temp->next != NULL && (!(item == temp->next->data)))
            {
                temp = temp->next;
            }
            // Create target node.
            Node* target = temp->next;
            // If target exist.
            if (target != NULL)
            {
                //
                temp->next = target->next;
                // Delete the target.
                delete target;
                // Decrease the length.
                length--;
            }
        }
    }
}

/**
 * Checks if the list is full by seeing if we can add a node in it. Big O(1) runtime.
 */
bool LinkedList::isFull() const
{
    Node* location;

    try
    {
        // If we can add a new node with no problem then return false for not full.
        location = new Node();
        delete location;
        return false;
    } catch(bad_alloc exception) {
        // It is full so we catch an exception.
        return true;
    }
}

/**
 * Empties the list by using pointers. Big O(n) runtime.
 */
void LinkedList::makeEmpty()
{
    Node* temp;
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
 * Getter for length. Big O(1) runtime.
 */
int LinkedList::getLength() const
{
    return length;
}

/**
 * Deconstructor for LinkedList. Empties the list as soon as program terminates. Big O(n) runtime.
 */
LinkedList::~LinkedList()
{
    // Calls make empty method as it handles deleting everything in the list.
    makeEmpty();
}

/**
 * Prints all data in the list using a temp pointer. Big O(n) runtime.
 */
void LinkedList::show()
{
    Node* temp = start;
    // While there is a node in list.
    while (temp != NULL)
    {
        // Since temp is set to first node print that first node's data.
        cout << temp->data << endl;
        // Now temp pointer to the next node and it will loop and output until the end of list.
        temp = temp->next;
    }
}
